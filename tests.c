#define TEST(tests...)                                                         \
  int main() {                                                                 \
    int failed = 0;                                                            \
    tests;                                                                     \
    if (failed) {                                                              \
      printf("\n\x1B[31m%d TESTS FAILED\x1B[0m\n", failed);                    \
      return 1;                                                                \
    } else {                                                                   \
      printf("\n\x1B[32mALL TESTS PASSED\x1B[0m\n");                           \
      return 0;                                                                \
    }                                                                          \
  }

#define UNIT(name, expr...)                                                    \
  {                                                                            \
    char testname[] = name;                                                    \
    int unitfailed = 0;                                                        \
    expr;                                                                      \
    if (unitfailed) {                                                          \
      printf("\x1B[31m[FAILED] %s\x1B[0m\n", testname);                        \
      failed++;                                                                \
    } else {                                                                   \
      printf("\x1B[32m[PASSED] %s\x1B[0m\n", testname);                        \
    }                                                                          \
  }

#define ASSERT(A, B)                                                           \
  if (A != B) {                                                                \
    unitfailed++;                                                              \
  }

#include <stdio.h>

#include "lib/search.h"
#include "lib/sort.h"

TEST({
  UNIT("linear search: element found", {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(arr[0]);
    int result = lsearch(arr, size, 5);

    ASSERT(result, 4);
  });

  UNIT("linear search: element not found", {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(arr[0]);
    int result = lsearch(arr, size, 11);

    ASSERT(result, -1);
  });

  UNIT("binary search: element found", {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(arr[0]);
    int result = bsearch(arr, size, 5);

    ASSERT(result, 4);
  });

  UNIT("binary search: element not found", {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(arr[0]);
    int result = bsearch(arr, size, 11);

    ASSERT(result, -1);
  });

  UNIT("bubble sort: ascending", {
    int arr[] = {3, 2, 1, 4, 0};

    int size = sizeof(arr) / sizeof(arr[0]);
    bsort(arr, size);

    for (int i = 0; i < size; i++) {
      ASSERT(arr[i], i);
    }
  });

  UNIT("insertion sort: ascending", {
    int arr[] = {3, 2, 1, 4, 0};

    int size = sizeof(arr) / sizeof(arr[0]);
    isort(arr, size);

    for (int i = 0; i < size; i++) {
      ASSERT(arr[i], i);
    }
  });

  UNIT("selection sort: ascending", {
    int arr[] = {3, 2, 1, 4, 0};

    int size = sizeof(arr) / sizeof(arr[0]);
    ssort(arr, size);

    for (int i = 0; i < size; i++) {
      ASSERT(arr[i], i);
    }
  });
})
