#include "sort.h"

#include <stdio.h>
#include <string.h>

#include "utils.h"

TEST({
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
})
