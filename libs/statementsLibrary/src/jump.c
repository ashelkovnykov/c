#include <stdio.h>

#include "../headers/jump.h"

/**
 * There are four jump statements which can be used to control the flow of a C program:
 *
 * 1. break: The break command exits the current loop entirely.
 * 2. continue: The continue command jumps directly to the end of the loop, skipping all commands remaining in the current iteration of the loop.
 * 3. return: The return command exits a function. Depending on the return type of the function, it may take an argument, which is the value that it
 *            returns.
 * 4. goto: The goto command jumps directly to the labelled statement with the identifier passed to the command as input.
 */
void printJump() {
  
  int x = 0;
  
  puts("Printing 1 through 5:\n");
  
  goto two;
  
one:
  puts("2");
  
  while (1) {
    ++x;
    
    if (x > 5) {
      break;
    } else if (x > 2) {
      printf("%d", x);
      continue;
    }
    
    ++x;
  }
  
  return;
  
two:
  puts("1");
  goto one;
}
