#ifndef SEM3_DSA_C_UTILS_H
#define SEM3_DSA_C_UTILS_H

// #define DEBUG

#ifdef DEBUG
#define D(x...) x
#else
#define D(x...)
#endif  // DEBUG

#define TEST(tests...)                                      \
  int main() {                                              \
    int failed = 0;                                         \
    tests;                                                  \
    if (failed) {                                           \
      printf("\n\x1B[31m%d TESTS FAILED\x1B[0m\n", failed); \
      return 1;                                             \
    } else {                                                \
      printf("\n\x1B[32mALL TESTS PASSED\x1B[0m\n");        \
      return 0;                                             \
    }                                                       \
  }

#define UNIT(name, expr...)                             \
  {                                                     \
    char testname[] = name;                             \
    int unitfailed = 0;                                 \
    expr;                                               \
    if (unitfailed) {                                   \
      printf("\x1B[31m[FAILED] %s\x1B[0m\n", testname); \
      failed++;                                         \
    } else {                                            \
      printf("\x1B[32m[PASSED] %s\x1B[0m\n", testname); \
    }                                                   \
  }

#define ASSERT(A, B) \
  if (A != B) {      \
    unitfailed++;    \
  }

#endif  // SEM3_DSA_C_UTILS_H
