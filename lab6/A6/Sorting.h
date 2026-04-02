#ifndef SORTING_H
#define SORTING_H

#include <string>

void swap(int* arr, int i, int j) {
	/**
	 * Swaps the element of index i and the element of index j in the arr.
	 *
	 * @param arr, int*, the pointer of the array
	 * @param i, int, the index of the first element
	 * @param j, int, the index of the second element
	 *
	 */
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void print_array(int* arr, string name, int size) {
	/**
	 * Print each element in the array in order, with the array shape format.
	 *
	 * @param arr, int*, the pointer of the array
	 * @param name, string, the name of the array that will be displayed in the output
	 * @param size, int, as sizeof(array) won't work insize a method, because the array will be passed as pointer, and the array is decayed (Important!)
	 *
	 */
	cout << endl << name << ": " << endl;

	string line(size * 7 + 1, '-');

	cout << line << endl;
	printf("|");
	for (int i = 0; i < size; i++) {

		printf("%4d  |", arr[i]);
	}
	cout << endl;
	cout << line << endl << endl;
}


void merge(int* arr, int l, int m, int h) {
	/**
	 * Compares the elements in both left_arr and right_arr and put them into arr in the correct sorted orders.
	 *
	 * The logic of the implementation of the merge() method should be as follows:
	 *
	 * 1. Declare two int variables n1 an n2 for the size of the left and right auxilary arrays.
	 *    n1 should be initialized to the number of elements from index l to m
	 *    n2 should be initialized to the number of elements from index m+1 to h
	 *
	 * 2. Declare two int arrays left_arr and right_arr as the auxilary arrays for the merge() method
	 *    left_arr should have the size of n1
	 *    right_arr should have the size of n2
	 *
	 * 3. Use two for loops to copy the data from arr to the two auxilary arrays
	 *    left_arr should have the arr elements starting from index l, and the number of elements you need to copy is n1
	 *    right_arr should have the arr elements starting from index m + 1, and the number of elements you need to copy is n2
	 *
	 * 4. Declare 3 variables i, j, k to keep track of the loops
	 *    i is the index for keeping track of the left_arr positions
	 *    j is the index for keeping track of the right_arr positions
	 *    k is the index for keeping track of the arr positions that you want to put back to when you compare and merge
	 *    (Hint: as merge() can be called in many smaller pieces of the array, so the initial value of k should not be 0,
	 *     it should start from l, which is the low index of arr)
	 *
	 * 5. Use a loop that will continue as long as i and j indexes are still within the range of the sizes
	 *    (i.e. if i exceeds the size n1 or if j exceeds the size n2, the loop should stop)
	 *
	 * 6. Inside the loop of step5, index i and j increases separatedly.
	 *    We will compare the values of the left_arr and right_arr, pick the smaller one and store it back to the arr:
	 *        > If we find that the current element in left_arr is smaller (or equals) than the element in right_arr,
	 *          the one in the left_arr will be stored to arr, index of left_arr will increase by 1
	 *        > If we find that the current element in left_arr is NOT smaller (or equals) than the element in right_arr,
	 *          the one in the right_arr will be stored to arr, index of right_arr will increase by 1
	 *    As no matter in which case, there must be one element stored in the arr,
	 *    so the index of arr should also increase by 1 in each iteration.
	 *
	 * 7. As in step6, we are doing comparision and will pick an element from either left_arr or right_arr to arr,
	 *    when the loop of step5 and step6 ends, which means one of the two arrays have reach its end,
	 *    so the comparison cannot continue, there must be element(s) left in either left_arr or right_arr.
	 *    To take care of the orphans (the elements not yet stored back to arr), we need to continue to loop through
	 *    the left_arr and right_arr to see which one still have the remaining elements.
	 *
	 *    Since we have finished the loop in step5 and step6, the indexes i and j still keeping track of the indexes
	 *    where left_arr and right_arr left off, so we can use two loops to take care of them:
	 *        > one loop that will continue the current index i in left_arr, if the index i has not reached the end,
	 *          the loop will go through each element in left_arr and store it to arr, and each time it stores the
	 *          elements to arr, the index of left_arr and arr should also increase by 1
	 *        > one loop that will continue the current index j in right_arr, if the index j has not reached the end,
	 *          the loop will go through each element in right_arr and store it to arr, and each time it stores the
	 *          elements to arr, the index of right_arr and arr should also increase by 1
	 *
	 * (8. If you create your auxilary arrays in heap memory, delete the arrays.)
	 *
	 * @param arr, int*, the pointer of the array
	 * @param l, int, the low index of the array
	 * @param m, int, the middle index of the array
	 * @param h, int, the high index of the array
	 *
	 */
	 // step1
	 int n1 = m - l + 1;
	 int n2 = h - m;

	 // step2
	 int* left_arr = new int[n1];
	 int* right_arr = new int[n2];

	 // step3
	 for (int i = 0; i < n1; i++)
	 	left_arr[i] = arr[l + i];

	 for (int j = 0; j < n2; j++)
		right_arr[j] = arr[m + 1 + j];

	 // step4
	 int i = 0, j = 0, k = l;
	 while (i < n1 && j < n2) {
	 	if (left_arr[i] <= right_arr[j]) {
	 		arr[k] = left_arr[i];
	 		i++;
		} else {
	 		arr[k] = right_arr[j];
	 		j++;
		}
	 	k++;
	 }
	 
	 // step5-step7
	 while (i < n1) {
	 	arr[k] = left_arr[i];
	 	i++;
	 	k++;
	 }
	 while (j < n2) {
	 	arr[k] = right_arr[j];
	 	j++;
	 	k++;
	 }

	// step8
	delete[] left_arr;
	delete[] right_arr;
}

void merge_sort(int* arr, int l, int h) {
	/**
	 * Splits arr into two halves using a middle point m,
	 * it will recursively do this as long as the low index l is still smaller than high index h,
	 * when the split arrays are small enough that cannot do further splitting,
	 * it will try to consider the elements on the left half and right half and merge them together in the correct order.
	 *
	 * @param arr, int*, the pointer of the array
	 * @param l, int, the low index of the array
	 * @param h, int, the high index of the array
	 *
	 */

	if (l < h) {
		int m = l + (h - l) / 2;   // equivalent to (l+h)/2 but avoided overflow, e.g. if (l+h) is a superhuge number 

		merge_sort(arr, l, m);     // sort first half
		merge_sort(arr, m + 1, h); // sort second half

		merge(arr, l, m, h);       // merge two halves together
	}

}


int partition(int* arr, int l, int h) {
	/**
	 * Pick an element to be the pivot (in this method, it will pick the last one),
	 * we will compare all the elements (other than the pivot itself) with the pivot,
	 * if we find the element is smaller than the pivot, we try to swap it to make its position not exceeding i,
	 * so that we can place the pivot at position i + 1, that way, all the elements before the pivot will be
	 * smaller or equal to pivot, and the elements after the pivot will be larger.
	 *
	 * The logic of the implementation of the partition() method should be as follows:
	 *
	 *
	 * swap() method has been implemented,
	 * the method call of swap() is:
	 *
	 *   swap(array_pointer, start_index, end_index)
	 *
	 * i.e. swap(arr, i, j)
	 *
	 * 1. Declare 3 int variables pivot, i, j.
	 *    pivot is to store the index of the element we use as the pivot,
	 *    i is to keep track of the position where we want to place the pivot at,
	 *    j is to keep track of the elements we compare in a loop,
	 *    We will initialize them in later steps.
	 *
	 * (2. This step is optional, if you want to try to achieve the best performance of quick sort O(nlogn),
	 *     you can do this additional step to randomly pick one of the element in the partition to be the pivot.
	 *     In this method, as we will set the pivot to be the last element, what you need to do is:
	 *
	 *     #include <cstdlib>          // to use srand(), rand(), you need to include the C++ standard library
	 *
	 *     int randomPickPosition = l + rand() % (h - l + 1); // low + random number the size between low~high
	 *
	 *     and then you will need to swap that randomPickPosition with the last index of the array, so that
	 *     this randomly picked element will be placed in the last element, and thus will be the pivot)
	 *
	 * 3. Assign the last element in arr to the variable pivot.
	 *
	 * 4. Initialize the i to 1 smaller than the low index (because we will swap the pivot with i + 1 element later)
	 *
	 * 5. Using a loop that will use j as the counter variable, the range of j should be l to h - 1.
	 *
	 * 6. In the loop of step5, for each element of index j in arr, we will compare it with pivot.
	 *       > If the current element at index j is smaller or equal to pivot,
	 *         we will increase the position that we want to keep track the ideal pivot position (which is i) by 1
	 *       > and then swap the element at i and the current element in the array
	 *         (so that the current element, which is smaller than pivot will be swapped to the position i)
	 *
	 * 7. After the loop in step5 and step6 ends, we have already placed all the elements smaller or equal to pivot
	 *    from indexes l to i, that means if we have the pivot at i + 1, all on the left side will be smaller
	 *    or equal to pivot, and all on the right side will be larger than pivot.
	 *    Thus, now we want to swap the last element (the pivot) with the element at i + 1.
	 *    (The current i+1 element before swapping is larger than the pivot, so it is correct to place it to the last)
	 *
	 * 8. return the correct pivot position, which is i + 1.
	 *
	 *
	 * @param arr, int*, the pointer of the array
	 * @param l, int, the low index of the array
	 * @param h, int, the high index of the array
	 *
	 */

	// step1
	int pivot, i, j;

	// step2 (optional)
	// int randomPickPosition = l + rand() % (h - l + 1);
	// swap(arr, randomPickPosition, h);

	// step3
	pivot = arr[h];

	// step4
	i = l - 1;	

	// step5 and step6
	for (j = l; j < h; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr, i, j);
		}
	}

	// step7
	swap(arr, i + 1, h);

	// step8
	return i + 1;
}

void quick_sort(int* arr, int l, int h) {
	/**
	 * Do the partitions and place a pivot at the correct position one at a time,
	 * it will recursively do this as long as the low index l is still smaller than high index h,
	 * at the time all the pivots in the arr are placed in the correct positions, the array will be sorted correctly.
	 *
	 * @param arr, int*, the pointer of the array
	 * @param l, int, the low index of the array
	 * @param h, int, the high index of the array
	 *
	 */

	int pivot;
	if (l < h) {
		pivot = partition(arr, l, h);  // do partition on the array from l to h and return the updated pivot
		quick_sort(arr, l, pivot - 1); // do partition on the part before pivot
		quick_sort(arr, pivot + 1, h); // do partition on the part after pivot
	}
}



#endif // SORTING_H