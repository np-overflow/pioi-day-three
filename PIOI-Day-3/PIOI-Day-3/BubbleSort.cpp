#include "BubbleSort.h"

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // outer loop to traverse through the array
        for (int j = 0; j < n - i - 1; j++) { // inner loop to compare adjacent elements
            if (arr[j] > arr[j + 1]) { // swap elements if they are in the wrong order
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}