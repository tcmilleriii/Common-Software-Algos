#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

// Coupled scripts below execute a quicksort algorithm, ordering an array from smallest
// to largest.

// This is a divide and conquer algorithm that pick an element as a 
// pivot and partitions the given array around the picked pivot by placing
// the pivot in its correct position in the sorted array.

// REFERENCE: https://www.geeksforgeeks.org/quick-sort/

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
