#include "CountingSort.h"

// This function takes an array of integers arr[] and its size n as input
void counting_sort(int arr[], int n) {
    // Find the range of input elements
    int range = *max_element(arr, arr + n) + 1;

    // Allocate the count array on the heap and initialize it to all zeros
    int* count = new int[range] {0};

    // Count the frequency of each input element and store it in the count array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Calculate the cumulative frequency of each input element in the count array
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Allocate the output array on the heap
    int* output = new int[n];

    // Traverse the input array in reverse order and place each element in its correct position in the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the input array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free the allocated memory
    delete[] count;
    delete[] output;
}