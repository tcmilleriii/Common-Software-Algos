#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include "binary_search.hpp"

// This script executes my Binary Sort Algorithm for whatever example case the user wishes
// to try out. It leverages the template version of binary_search located in binary_search.hpp.

// In this main.cpp function, we're calling the template based on the types we've chosen for 
// a few other variables: namely, search_me, curr, and find_me. Changing those would requires
// that you redefine the variable types when we instantiate the recursiveBinarySearch template
// function.

// INPUT FORMAT:
//  - User defines (via std::cin) a SORTED array.
    // N <-- number of elements
    // x1 x2 x3 ... xN <-- elements themselves
// OUTPUT:
//  - Algorithm outputs the index at which the desired value exists.



int main(){

    // User defines (via std::cin) an array of integers.
    std::cout << "Provide a sorted array of integers: " << std::endl;
    int N;
    std::cin >> N;
    std::vector<double> search_me;
    double curr;
    for (int i = 0; i < N; i++){
        std::cin >> curr;
        search_me.push_back(curr);
    }

    // User defines a value they want searched for.
    double find_me;
    std::cout << "Indicate the value you wish to find in the array. If it doesn't exist, the index of the value nearest (but less than) it will be provided: " << std::endl;
    std::cin >> find_me;

    // Call binary search.
    int winning_index = -1;

    recursiveBinarySearch<std::vector<double>, double, double, double, int>(search_me,0,search_me.size(),find_me,winning_index);

    std::cout << "The index of your variable was: " << winning_index << std::endl;
    return winning_index;
}