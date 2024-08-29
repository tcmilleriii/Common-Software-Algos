#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

// Merge sort algorithm. Take an unsorted array, split it continually (done via recursion),
// then sort once we're at the lowest level (fully split).

void merge(int *arr, int left, int mid, int right){

    // size the left and right arrays.
    int leftsize = mid - left + 1;
    int rightsize = right - mid;

    // Construct the two arrays from this current level.
    int *left_arr = new int[leftsize];
    int *right_arr = new int[rightsize];

    // Loop through and store off these left and right arrays.
    for (int i = 0; i < leftsize; i++){
        left_arr[i] = arr[left + i];
    }
    for (int j = 0; j < rightsize; j++){
        right_arr[j] = arr[mid + 1 + j];
    }

    // Iterate through the left array, right array, and zip their data back up into the larger parent array.
    int left_arr_index = 0;
    int right_arr_index = 0;
    int arr_index = left;

    while ((left_arr_index < leftsize) && (right_arr_index < rightsize)){

        if (left_arr[left_arr_index]<= right_arr[right_arr_index]){
            arr[arr_index] = left_arr[left_arr_index];
            left_arr_index++;
        }
        else{
            arr[arr_index] = right_arr[right_arr_index];
            right_arr_index++;
        }

        arr_index++;
    }

    // Copy the remaining elements of left array (if there are any)
    while (left_arr_index < leftsize) {
        arr[arr_index] = left_arr[left_arr_index];
        left_arr_index++;
        arr_index++;
    }
 
    // Copy the remaining elements of right array (if there are any)
    while (right_arr_index < rightsize) {
        arr[arr_index] = right_arr[right_arr_index];
        right_arr_index++;
        arr_index++;
    }

    delete[] left_arr;
    delete[] right_arr;


}

void mergeSort(int *arr, int start, int end){

    // Define midpoint.
    int mid = start + (end - start) / 2;

    // Step up a level if we've gotten down to a single index.
    if (start >= end){

        return;

    } else{

        // Call mergeSort on the two subarrays.
        mergeSort(arr, start, mid); // Will hit this leg over and over until we're down to one index.
        mergeSort(arr, mid+1, end); // Will then hit this leg over and over until we're also down to one index.
        merge(arr, start, mid, end);
    }

}

int main(){

    // User defines an array (can be completely unsorted).
    std::cout << "Enter an array. Can be unsorted (in fact, should be). Start with a size." << std::endl;

    // Size of the array.
    int N;
    std::cin >> N;

    // Iteratively add to the array. We're going with the C-style technique instead of standard library.
    int *arr = new int[N];
    int barf;
    for (int i = 0; i < N; i++){
        std::cin >> barf;
        arr[i] = barf;
    }

    // Now execute the merge-sort algorithm. Could do this with vectors but you need the practice.
    mergeSort(arr, 0, N-1);

    // DEBUG CONTENT - check arr
    for (int i = 0; i < N; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}