#include <stdio.h>

#include "settings.h"

#ifdef CUSTOM_MATH
#include "mathLib.h"
#endif

int main(int argc, char *argv[]) {
  
  printf("Version: %s\n", VERSION);

#ifdef CUSTOM_MATH
  printf("Square of 2 = %f\n", mySqr(2.0));
#else
  printf("Square of 2 = %f\n", (2.0 * 2.0));
#endif
  
  return 0;
}