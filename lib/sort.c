#include "sort.h"

/*
 * Bubble Sort
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 * This algorithm will sort the array in ascending order,
 * using the bubble sort algorithm.
 */
void bubble_sort(int array[], int size) {
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

/*
 * Insertion Sort
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 * This algorithm will sort the array in ascending order,
 * using the insertion sort algorithm.
 */
void insertion_sort(int array[], int size) {
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

/*
 * Selection Sort
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 * This algorithm will sort the array in ascending order,
 * using the selection sort algorithm.
 */
void selection_sort(int array[], int size) {
  int temp;
  for (int i = 0; i < size; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[min]) {
        min = j;
      }
    }
    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
  }
}
