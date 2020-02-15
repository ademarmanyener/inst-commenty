#include "l_lib.h"

void l_printHeader(){
  system("clear");
  printf("\n\t===============================\n");
  printf("\n\t\t%s\n", APP_NAME);
  printf("\n\t===============================\n");
  return;
}

char *l_mainWindow(char *msg){
  l_printHeader();
  char *return_value = malloc(strlen(msg)+2);
  printf("\t-> %s", msg);
  gets(return_value);
  return return_value;
}

void l_resultWindow(char *username, char *password, char *address, char *message, int message_count){
  l_printHeader();
  printf("\t==> Username: %s\n", username);
  printf("\t==> Password: %s\n", password);
  printf("\t==> Address: %s\n", address);
  printf("\t==> Message: %s\n", message);
  printf("\t==> Message Count: %d\n", message_count);
  printf("\t===============================\n");
  printf("\tDo you confirm? (yes/no): ");
  char *return_value = malloc(10);
  gets(return_value);
  if (strcmp(return_value, "yes") == 0)
    for (int i=0; i<message_count; i++)
      printf("yesss\n");
  else {
    system("clear");
    g_error_message("cancelled");
  }
  return;
}

int l_main(int argc, char *argv[]){
  char *username = l_mainWindow("Enter your username: ");
  char *password = l_mainWindow("Enter your password: ");
  char *address = l_mainWindow("Enter post address: ");
  char *message = l_mainWindow("Enter your message: ");
  int message_count = atoi(l_mainWindow("Enter message count: "));
  l_resultWindow(username, password, address, message, message_count);
  return 0;
}
