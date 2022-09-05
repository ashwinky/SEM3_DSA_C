#ifndef SEM3_DSA_C_UTILS_H
#define SEM3_DSA_C_UTILS_H

#ifdef DEBUG
#define D(x...) x
#else
#define D(x...)
#endif  // DEBUG

#define TEST(name, tests...) \
  int main() {               \
    char testname[] = name;  \
    int failed = 0;          \
    tests;                   \
    if (failed) {            \
      return 1;              \
    } else {                 \
      return 0;              \
    }                        \
  }

#define UNIT(name, expr...)                                           \
  {                                                                   \
    char unitname[] = name;                                           \
    int unitfailed = 0;                                               \
    expr;                                                             \
    if (unitfailed) {                                                 \
      printf("\x1B[31m[FAILED] %s: %s\x1B[0m\n", testname, unitname); \
      failed++;                                                       \
    } else {                                                          \
      printf("\x1B[32m[PASSED] %s: %s\x1B[0m\n", testname, unitname); \
    }                                                                 \
  }

#define ASSERT(A, B) \
  if (A != B) {      \
    unitfailed++;    \
  }

#endif  // SEM3_DSA_C_UTILS_H
