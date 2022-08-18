#include "search.h"

#include <stdio.h>

#include "utils.h"

TEST({
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
})
