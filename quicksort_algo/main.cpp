#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

// This is the main run file for executing a quicksort algo. 
// REFERENCE: https://www.geeksforgeeks.org/quick-sort/

// This is a divide and conquer algorithm that pick an element as a 
// pivot and partitions the given array around the picked pivot by placing
// the pivot in its correct position in the sorted array.

int partition(std::vector<int>& arr, int& low, int& high) {

    // set pivot value.
    int pivot = arr[high];

    // set i, which will be a slow iterator to step from left to right through array.
    int i = low - 1;

    for (int j = low; j <= high; j++){
        if (arr[j] < pivot){
            i++;
            std::swap(arr[i],arr[j]);
        }
    }

    std::swap(arr[i+1],arr[high]);
    return (i+1);
}

void partitionParent(std::vector<int> &arr, int low, int high){

    // determine if low is less than high, otherwise we're done.
    if (low < high){

        // This places value from 'high' index of array in the right spot
        // and then outputs the index it was placed at.
        int partitioner = partition(arr, low, high);

        // recursive call on the two halves of the partitioned array. All left side values get finished before rights. 
        partitionParent(arr,low,partitioner-1); 
        partitionParent(arr,partitioner+1,high);
    }
}

int main(){

    // Begin by the user providing an array. This will be done using the standard
    // toolbox.
    int N;
    std::cout << "Provide the size of the array: ";
    std::cin >> N;
    std::cout << std::endl;
    std::cout << "Now enter the array itself: ";

    // Intake the (probably) unsorted array.
    std::vector<int> arr;
    int curr;
    for (int i = 0; i < N; i++){
        std::cin >> curr;
        arr.push_back(curr);
    }

    // Get a sorted version of the original array (for use in final checkoff).
    std::vector<int> truth_vec = arr;
    std::sort(truth_vec.begin(),truth_vec.end());

    // Enter a recursion parent function that calls the partition function. 
    // At this highest level we use a 'low' and 'high' value at either end of the
    // full size of the array.
    partitionParent(arr, 0, N-1);

    return 0;
}