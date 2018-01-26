#include "pipe_networking.h"
#include "forking_server.h"
#include "subserver.h"
#include "startup.h"


static void sighandler(int signo) {
  if (signo == SIGINT) {
    remove("pubwkp");
    exit(0);
  }
}

int main() {
  signal(SIGINT, sighandler);
  startuptext(1);
  root_folder();

  int from_client;
  int parent;

  printf(GREEN_BOLD "[PUBServer]" COLOR_RESET);
  printf(" Waiting for new connection...\n");
  while (1) {
    from_client = server_setup();
    parent = fork();
    if (!parent) {
      subserver(from_client);
    }
    else {
      close(from_client);
    }
  }
}

void root_folder() {
  if (access("users", F_OK) != -1) {
    printf(GREEN_BOLD "[PUBServer]" COLOR_RESET);
    printf(" Root users folder found!\n");
  }
  else {
    mkdir("users", 0700);
    printf(GREEN_BOLD "[PUBServer]" COLOR_RESET);
    printf(" Root users folder created!\n");
  }
}