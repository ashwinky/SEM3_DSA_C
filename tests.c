#include <stdio.h>
#include <string.h>

#include "eval.h"
#include "search.h"
#include "sort.h"
#include "stack.h"
#include "utils.h"

TEST({
  // Search
  UNIT("linear search: element found", {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(arr[0]);
    int result = linear_search(arr, size, 5);

    ASSERT(result, 4);
  });

  UNIT("linear search: element not found", {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(arr[0]);
    int result = linear_search(arr, size, 11);

    ASSERT(result, -1);
  });

  UNIT("binary search: element found", {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binary_search(arr, size, 5);

    ASSERT(result, 4);
  });

  UNIT("binary search: element not found", {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binary_search(arr, size, 11);

    ASSERT(result, -1);
  });

  // Sort
  UNIT("bubble sort: ascending", {
    int arr[] = {3, 2, 1, 4, 0};

    int size = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, size);

    for (int i = 0; i < size; i++) {
      ASSERT(arr[i], i);
    }
  });

  UNIT("insertion sort: ascending", {
    int arr[] = {3, 2, 1, 4, 0};

    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, size);

    for (int i = 0; i < size; i++) {
      ASSERT(arr[i], i);
    }
  });

  UNIT("selection sort: ascending", {
    int arr[] = {3, 2, 1, 4, 0};

    int size = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, size);

    for (int i = 0; i < size; i++) {
      ASSERT(arr[i], i);
    }
  });

  // Stack
  UNIT("stack push: empty stack", {
    int stack[5];
    stack_push(stack, 0, 1);
    ASSERT(stack[0], 1);
  });

  UNIT("stack pop: non-empty stack", {
    int stack[5] = {3, 2, 1, 4, 0};
    int result = stack_pop(stack, 4);
    ASSERT(result, 0);
  })

  // Eval
  UNIT("eval: simple expression", {
    char infix[] = "A+B";
    char postfix[4];

    char result[] = "AB+";

    infixToPostfix(infix, postfix);

    for (int i = 0; i < strlen(postfix); i++) {
      ASSERT(postfix[i], result[i]);
    }
  })

  UNIT("eval: complex expression", {
    char infix[] = "A+B*C-(D/E^F)*G";
    char postfix[20];

    char result[] = "ABC*+DEF^/G*-";

    infixToPostfix(infix, postfix);

    for (int i = 0; i < strlen(postfix); i++) {
      ASSERT(postfix[i], result[i]);
    }
  })
})
