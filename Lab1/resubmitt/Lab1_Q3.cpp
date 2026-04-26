#include <iostream>
#include <cstdlib>
using namespace std;

int find_smallest(int a[], int size) {
    // Base case: only one element left
    if (size == 1) {
        return a[0];
    }
    
    // Recursive case: find smallest in the rest of the array
    int smallest_in_rest = find_smallest(a, size - 1);
    
    // Compare last element with smallest in the rest
    if (a[size - 1] < smallest_in_rest) {
        return a[size - 1];
    } else {
        return smallest_in_rest;
    }
}
int main(int argc, char* argv[]) {
int arr[] = {5, 92, 38, 71, 16, 84, 47, 60, 13, 99, 28, 54, 3, 79, 41, 65};
cout<< "smallest: " << find_smallest(arr, 16) << endl;
}