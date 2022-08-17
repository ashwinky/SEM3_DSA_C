#include "stack.h"

void stack_push(int stack[], int next, int value) { stack[next] = value; }

int stack_pop(int stack[], int curr) {
  int value = stack[curr];
  stack[curr] = 0;
  return value;
}
