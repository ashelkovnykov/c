#include <stdio.h>

#include "../headers/iteration.h"

void printIteration() {
  int n = 5;
  
  puts("Printing 1 through 5 using for loop:\n");
  for (int i = 1; i <= n; ++i) {
    printf("%d", i);
  }
  
  puts("\n");
  puts("Printing 1 through 5 using while loop:\n");
  while (n > 0) {
    printf("%d", 5 - --n);
  }
  
  puts("\n");
  puts("Printing 1 through 5 using do loop:\n");
  do {
    printf("%d", ++n);
  } while (n < 5);
}
