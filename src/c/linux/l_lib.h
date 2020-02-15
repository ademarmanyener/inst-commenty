#ifndef L_LIB
#define L_LIB

#include "../include/header.h"

void l_printHeader();
char *l_mainWindow(char *msg);
void l_resultWindow(char *username, char *password, char *address, char *message, int message_count);
int l_main(int argc, char *argv[]);

#endif //L_LIB
