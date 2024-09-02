#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include "binary_search.hpp"

// This script executes my Binary Sort Algorithm for whatever example case the user wishes
// to try out.

// In this main.cpp function, we're calling the template based on the types we've chosen for 
// a few other variables: namely, search_me, curr, and find_me. Changing those would require
// that we redefine the variable types when we instantiate the recursiveBinarySearch template
// function.

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

    std::cout << " Wining index was: " << winning_index << std::endl;
    return winning_index;
}