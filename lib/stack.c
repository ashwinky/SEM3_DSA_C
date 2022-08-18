#include "stack.h"

/*
 * Push an element to the top of the stack
 */
void stack_push(int stack[], int next, int value) { stack[next] = value; }

/*
 * Pop an element from the top of the stack
 */
int stack_pop(int stack[], int curr) {
  int value = stack[curr];
  stack[curr] = 0;
  return value;
}
