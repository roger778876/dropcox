#define RED_TEXT "\x1B[31m"
#define GREEN_TEXT "\x1b[32m"
#define GREEN_BOLD  "\x1B[32;1m"
#define COLOR_RESET "\x1b[0m"

int to_server;
int from_server;
void login(); // Prompts user for a username, sends to subserver.
void shell(); // Starts the command shell.