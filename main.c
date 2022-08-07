#include "lib/search.h"
#include <stdio.h>

int main() {
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  int i = bsearch(arr, sizeof(arr) / sizeof(arr[0]), 3);
  int j = lsearch(arr, sizeof(arr) / sizeof(arr[0]), 3);

  printf("%d %d\n", i, j);

  return 0;
}
