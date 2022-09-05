#include "sort.h"

#include <stdio.h>
#include <string.h>

#include "utils.h"

TEST("sort", {
  UNIT("bubble: ascending", {
    int arr[] = {3, 2, 1, 4, 0};

    int size = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, size);

    for (int i = 0; i < size; i++) {
      ASSERT(arr[i], i);
    }
  });

  UNIT("insertion: ascending", {
    int arr[] = {3, 2, 1, 4, 0};

    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, size);

    for (int i = 0; i < size; i++) {
      ASSERT(arr[i], i);
    }
  });

  UNIT("selection: ascending", {
    int arr[] = {3, 2, 1, 4, 0};

    int size = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, size);

    for (int i = 0; i < size; i++) {
      ASSERT(arr[i], i);
    }
  });
})
