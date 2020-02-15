#include "include/header.h"

int main(int argc, char *argv[]){
  if (strcmp(OS, "linux") == 0)
    l_main(argc, argv);
  if (strcmp(OS, "windows") == 0)
    w_main(argc, argv);
  return 0;
}
