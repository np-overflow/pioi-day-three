#include "MergeSort.h"

void merge(int arr[], int left, int mid, int right) {
    // Compute the sizes of the two sub-arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Allocate memory for the temporary arrays using dynamic memory allocation
    int* left_arr = new int[n1];
    int* right_arr = new int[n2];

    // Copy the elements of the two sub-arrays into the temporary arrays
    for (int i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];

    // Merge the two temporary arrays into the original array in sorted order
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from the left sub-array
    while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    // Copy any remaining elements from the right sub-array
    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }

    // Free the dynamically allocated memory using the delete[] keyword
    delete[] left_arr;
    delete[] right_arr;
}

/* merge sort function */
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // calculate the middle index

        /* recursively sort the left and right halves */
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        /* merge the sorted halves */
        merge(arr, left, mid, right);
    }
}
