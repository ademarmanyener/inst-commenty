#include "l_lib.h"

void l_runApp(char *username, char *password, char *address, char *message){
  char command[500] = "python3 src/py/app.py --username ";
  strcat(command, username);
  strcat(command, " --password ");
  strcat(command, password);
  strcat(command, " --addr ");
  strcat(command, address);
  strcat(command, " --msg '");
  strcat(command, message);
  strcat(command, "' 2>/dev/null");
  system(command);
  return;
}

void l_printHeader(){
  system("clear");
  printf("\n\t===============================\n");
  printf("\n\t\t%s\n", APP_NAME);
  printf("\n\t===============================\n");
  return;
}

char *l_mainWindow(char *msg){
  l_printHeader();
  char *return_value = malloc(300);
  if (strcmp(msg, "Enter your password: ") == 0){
    char pass_msg[25] = "\t-> ";
    strcat(pass_msg, msg);
    return_value = getpass(pass_msg);
  } else {
    printf("\t-> %s", msg);
    gets(return_value);
  }
  return return_value;
}

void l_resultWindow(char *username, char *password, char *address, char *message, int message_count){
  l_printHeader();
  printf("\t==> Username: %s\n", username);
  printf("\t==> Password: ", "***");
  for (int i=0; i<strlen(password); i++)
    printf("*");
  printf("\n");
  printf("\t==> Address: %s\n", address);
  printf("\t==> Message: %s\n", message);
  printf("\t==> Message Count: %d\n", message_count);
  printf("\t===============================\n");
  printf("\tDo you confirm? (yes/no): ");
  char *return_value = malloc(10);
  gets(return_value);
  if (strcmp(return_value, "yes") == 0){
    for (int i=0; i<message_count; i++){
      l_printHeader();
      printf("\tMessages're sending... (%d / %d)\n", i+1, message_count);
      l_runApp(username, password, address, message);
      printf("\n\tOK.\n\n");
    }
  } else {
    system("clear");
    g_error_message("cancelled");
  }
  return;
}

void l_checkGeckoDriver(){
  if (access("/usr/local/bin/geckodriver", F_OK) != -1){
    return;
  } else {
    system("sudo cp -r src/files/geckodriver /usr/local/bin/");
  }
  return;
}

int l_main(int argc, char *argv[]){
  l_checkGeckoDriver();
  char *username = l_mainWindow("Enter your username: ");
  char *password = l_mainWindow("Enter your password: ");
  char *address = l_mainWindow("Enter post address: ");
  char *message = l_mainWindow("Enter your message: ");
  int message_count = atoi(l_mainWindow("Enter message count: "));
  l_resultWindow(username, password, address, message, message_count);
  return 0;
}
