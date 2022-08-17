#ifndef SEM3_DSA_C_SEARCH_H
#define SEM3_DSA_C_SEARCH_H

// Linear Search
// Time Complexity: O(n)
// Space Complexity: O(1)
// This algorithm will find the index of the given target in the array.
int linear_search(const int array[], int size, int target);

// Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Assuming the array is sorted, this algorithm will
// find the index of the given target in the array.
int binary_search(const int array[], int size, int target);

#endif  // SEM3_DSA_C_SEARCH_H
