#ifndef SEM3_DSA_C_SORT_H
#define SEM3_DSA_C_SORT_H

#endif // SEM3_DSA_C_SORT_H

// Bubble Sort
// Time Complexity: O(n^2)
// Space Complexity: O(1)
void bsort(int array[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}