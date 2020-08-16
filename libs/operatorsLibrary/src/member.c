#include "../headers/member.h"

void printMember() {
  int array[1] = {1};
  int i = 2;
  struct T t = {3};
  struct T *pt;
  
  i = array[1];   // Array subscription
  i = *array;     // Pointer de-reference
  pt = &t;        // Address-of
  i = t.member;   // Member access
  i = pt->member; // Member access through pointer
}
