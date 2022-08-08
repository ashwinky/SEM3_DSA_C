#ifndef SEM3_DSA_C_SORT_H
#define SEM3_DSA_C_SORT_H

// Bubble Sort
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// This algorithm will sort the array in ascending order,
// using the bubble sort algorithm.
void bsort(int array[], int size) {
  int temp;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

// Insertion Sort
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// This algorithm will sort the array in ascending order,
// using the insertion sort algorithm.
void isort(int array[], int size) {
  int temp;
  // Loop through the array
  for (int i = 1; i < size; i++) {
    for (int j = i; j > 0; j--) {
      if (array[j] < array[j - 1]) {
        temp = array[j];
        array[j] = array[j - 1];
        array[j - 1] = temp;
      }
    }
  }
}

#endif // SEM3_DSA_C_SORT_H
