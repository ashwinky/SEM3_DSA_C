#define TEST(tests...)                                                         \
  int main() {                                                                 \
    int failed = 0;                                                            \
                                                                               \
    tests;                                                                     \
                                                                               \
    if (failed) {                                                              \
      printf("\x1B[0m\n\x1B[31m%d TESTS FAILED\n", failed);                    \
      return 1;                                                                \
    } else {                                                                   \
      printf("\x1B[0m\n\x1B[32mALL TESTS PASSED\n");                           \
      return 0;                                                                \
    }                                                                          \
  }

#define UNIT(name, expr...)                                                    \
  {                                                                            \
    char testname[] = name;                                                    \
                                                                               \
    expr;                                                                      \
  }

#define ASSERT(A, B)                                                           \
  if (A == B) {                                                                \
    printf("\x1B[32mPASS: %s\x1B[0m\n", testname);                             \
  } else {                                                                     \
    printf("\x1B[31mFAIL: %s\x1B[0m\n", testname);                             \
    printf("\t\x1B[31mExpected: %d\x1B[0m\n", B);                              \
    printf("\t\x1B[31mGot: %d\x1B[0m\n", A);                                   \
    failed++;                                                                  \
  }

#include <stdio.h>

#include "lib/search.h"

TEST({
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int size = sizeof(arr) / sizeof(arr[0]);

  UNIT("linear search: element found", {
    int result = lsearch(arr, size, 5);
    ASSERT(result, 4);
  });

  UNIT("linear search: element not found", {
    int result = lsearch(arr, size, 11);
    ASSERT(result, -1);
  });

  UNIT("binary search: element found", {
    int result = bsearch(arr, size, 5);
    ASSERT(result, 4);
  });

  UNIT("binary search: element not found", {
    int result = bsearch(arr, size, 11);
    ASSERT(result, -1);
  });
})
