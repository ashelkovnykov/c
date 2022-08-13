#include <stdio.h>

#include "../headers/selection.h"

/**
 * Two types of selection statements:
 * - if
 * - switch
 */
void printSelection() {
  puts("Testing if statement:\n");
  if (1 == 0) {
    puts("incorrect\n");
  } else if (1 < 0) {
    puts("incorrect\n");
  } else if (1 > 0) {
    puts("correct\n");
  } else {
    puts("incorrect\n");
  }
  
  puts("Printing 1 through 3 using switch statement:\n");
  switch (1) {
    case 3:
      puts("3");
    case 2:
      puts("2");
    case 1:
      puts("1");
  }
  switch (2) {
    case 1:
      puts("1");
    case 2:
      puts("2"); // Switch fall-through to next case after this one
    case 3:
      puts("3");
  }
}
