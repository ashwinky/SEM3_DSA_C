#include "stack.h"

#include <stdio.h>

#include "utils.h"

TEST("stack", {
  UNIT("push", {
    int stack[5];
    stack_push(stack, 0, 1);
    ASSERT(stack[0], 1);
  });

  UNIT("pop", {
    int stack[5] = {3, 2, 1, 4, 0};
    int result = stack_pop(stack, 4);
    ASSERT(result, 0);
  });
})
