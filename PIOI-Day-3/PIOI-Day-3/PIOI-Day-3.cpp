#include <iostream>

#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "CountingSort.h"
#include "RadixSort.h"

#include "HashTable.h"

using namespace std;

void sortingAlgorithms() {
    int arr[] = { 5, 2, 9, 1, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]); // calculate the size of the array
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Bubble Sort
    bubble_sort(arr, n); // sort the array using bubble sort
    cout << "Array sorted using bubble sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    // Selection Sort
    int sel_arr[] = { 5, 2, 9, 1, 5, 6 };
    n = sizeof(sel_arr) / sizeof(sel_arr[0]); // calculate the size of the array
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << sel_arr[i] << " ";
    }
    cout << endl;

    selection_sort(sel_arr, n); // sort the array using selection sort
    cout << "Array sorted using selection sort: ";
    for (int i = 0; i < n; i++) {
        cout << sel_arr[i] << " ";
    }
    cout << endl << endl;

    // Insertion Sort
    int ins_arr[] = { 5, 2, 9, 1, 5, 6 };
    n = sizeof(ins_arr) / sizeof(ins_arr[0]); // calculate the size of the array
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << ins_arr[i] << " ";
    }
    cout << endl;

    insertion_sort(ins_arr, n); // sort the array using insertion sort
    cout << "Array sorted using insertion sort: ";
    for (int i = 0; i < n; i++) {
        cout << ins_arr[i] << " ";
    }
    cout << endl << endl;

    // Merge Sort
    int merge_arr[] = { 38, 27, 43, 3, 9, 82, 10 };
    n = sizeof(merge_arr) / sizeof(merge_arr[0]);
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << merge_arr[i] << " ";
    }
    cout << endl;

    // Call merge_sort to sort the array
    merge_sort(merge_arr, 0, n - 1);

    // Print the sorted array
    cout << "Array sorted using merge sort: ";
    for (int i = 0; i < n; i++)
        cout << merge_arr[i] << " ";
    cout << endl << endl;

    // Counting Sort
    int count_arr[] = { 4, 2, 3, 1, 2, 4, 3 };
    n = sizeof(count_arr) / sizeof(count_arr[0]);
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << count_arr[i] << " ";
    }
    cout << endl;

    counting_sort(count_arr, n);

    cout << "Array sorted using counting sort: ";
    for (int i = 0; i < n; i++) {
        cout << count_arr[i] << " ";
    }
    cout << endl << endl;

    // Radix Sort
    int radix_arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    n = sizeof(radix_arr) / sizeof(radix_arr[0]);
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << radix_arr[i] << " ";
    }
    cout << endl;

    radix_sort(radix_arr, n);

    cout << "Array sorted using radix sort: ";
    for (int i = 0; i < n; i++) {
        cout << radix_arr[i] << " ";
    }
    cout << endl << endl;
}


int main() {
    sortingAlgorithms();

    HashTable dictionary;

    // add some items to the hash table
    dictionary.add("apple", "A sweet fruit");
    dictionary.add("banana", "A yellow fruit");
    dictionary.add("pear", "A juicy fruit");
    dictionary.add("orange", "A citrus fruit");
    dictionary.add("peach", "A fuzzy fruit");
    dictionary.add("grape", "A small fruit");
    dictionary.add("plum", "A purple fruit");

    // add an item that collides with "peach"
    dictionary.add("apepl", "Not a real fruit");

    // print the contents of the hash table
    dictionary.print();

    // remove an item
    dictionary.remove("orange");

    // check if the hash table is empty
    cout << "Is the dictionary empty? " << (dictionary.isEmpty() ? "Yes" : "No") << endl;

    // get an item
    cout << "The definition of 'pear' is: " << dictionary.get("pear") << endl;

    // get the length of the hash table
    cout << "The length of the dictionary is: " << dictionary.getLength() << endl;


    return 0;
}