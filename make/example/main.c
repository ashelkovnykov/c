#include <stdio.h>

#include "helper.h"

int main(int argc, char *argv[]) {
  
  for (int i = 1; i < argc; ++i) {
    printf("Command line argument #%d: %s\n", i, argv[i]);
  }
  
  helper();
  
  return 0;
}
