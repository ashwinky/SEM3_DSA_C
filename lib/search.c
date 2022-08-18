#include "search.h"

/*
 * Linear Search
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * This algorithm will find the index of the given target in the array.
 */
int linear_search(const int array[], int size, int target) {
  int result = -1;  // assume not found

  // loop through the array from [0..N]
  for (int i = 0; i < size; i++) {
    // if item is equal to current element
    if (array[i] == target) {
      result = i;  // set the result index
      break;       // exit loop
    }
  }

  // return the result index
  return result;
}

/*
 * Binary Search
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Assuming the array is sorted, this algorithm will
 * find the index of the given target in the array.
 */
int binary_search(const int array[], int size, int target) {
  // Start from [0..N]
  int min = 0;
  int max = size - 1;

  int result = -1;  // assume not found

  // loop until `min` and `max` converge at `mid`
  while (min <= max) {
    // set the mid-point index
    int mid = min + (max - min) / 2;

    // if item is equal to mid-element
    if (target == array[mid]) {
      result = mid;
      break;  // exit loop
    }
    // if item is lesser than mid-element
    else if (array[mid] > target) {
      max = mid - 1;
    }
    // if item is greater than mid-element
    else {
      min = mid + 1;
    }
  }

  return result;
}
