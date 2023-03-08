#include "InsertionSort.h"

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) { // loop to traverse through the array
        int key = arr[i]; // current element to be inserted
        int j = i - 1; // index of the element before the current element

        /* move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) { // find the correct position for the current element
            arr[j + 1] = arr[j]; // move the element to one position ahead
            j--;
        }

        arr[j + 1] = key; // insert the current element at the correct position
    }
}
