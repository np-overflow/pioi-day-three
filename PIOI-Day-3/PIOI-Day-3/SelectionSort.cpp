#include "SelectionSort.h"

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // outer loop to traverse through the array
        int min_index = i; // assume the current element is the minimum
        for (int j = i + 1; j < n; j++) { // inner loop to find the minimum element
            if (arr[j] < arr[min_index]) { // update the minimum element if a smaller element is found
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]); // swap the minimum element with the current element
    }
}
