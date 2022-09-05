#include "search.h"

#include <stdio.h>

#include "utils.h"

TEST("search", {
  UNIT("linear: element found", {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(arr[0]);
    int result = linear_search(arr, size, 5);

    ASSERT(result, 4);
  });

  UNIT("linear: element not found", {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(arr[0]);
    int result = linear_search(arr, size, 11);

    ASSERT(result, -1);
  });

  UNIT("binary: element found", {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binary_search(arr, size, 5);

    ASSERT(result, 4);
  });

  UNIT("binary: element not found", {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binary_search(arr, size, 11);

    ASSERT(result, -1);
  });
})
