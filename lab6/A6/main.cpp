#include <iostream>
using namespace std;

#include "Sorting.h"

int main() {
    int arr1[] = { 52, 17, 38, 29, 1, 45, 71, 4, 63 };
    int arr1_size = sizeof(arr1) / sizeof(arr1[0]);
    print_array(arr1, "arr1", arr1_size);

    merge_sort(arr1, 0, arr1_size - 1);
    print_array(arr1, "arr1(Merge Sort)", arr1_size);

    int arr2[] = { 26, 89, 12, 6, 23, 90, 2, 56, 43 };
    int arr2_size = sizeof(arr2) / sizeof(arr2[0]);
    print_array(arr2, "arr2", arr2_size);

    quick_sort(arr2, 0, arr1_size - 1);
    print_array(arr2, "arr2(Quick Sort)", arr2_size);
}