#include "RadixSort.h"


void radix_sort(int arr[], int n) {
    int max_num = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }
    int digits = ceil(log10(max_num + 1));
    int buckets[10] = { 0 };
    int* sorted_arr = new int[n];

    for (int d = 0; d < digits; d++) {
        int digit_pos = pow(10, d);

        // count the frequency of each digit in the current position
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / digit_pos) % 10;
            buckets[digit]++;
        }

        // calculate the starting index for each digit in the sorted array
        for (int i = 1; i < 10; i++) {
            buckets[i] += buckets[i - 1];
        }

        // place each number in the correct bucket and update the starting index
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / digit_pos) % 10;
            sorted_arr[buckets[digit] - 1] = arr[i];
            buckets[digit]--;
        }

        // copy the sorted array to the original array for the next iteration
        for (int i = 0; i < n; i++) {
            arr[i] = sorted_arr[i];
        }

        // reset the bucket counts
        for (int i = 0; i < 10; i++) {
            buckets[i] = 0;
        }
    }

    delete[] sorted_arr;
}