#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include "quicksort_algo.hpp"

// This main file lets users run example cases of the quicksort algorithm.

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