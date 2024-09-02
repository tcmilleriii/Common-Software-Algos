#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include "binary_search.hpp"

int main(){

    // User defines (via std::cin) an array of integers.
    std::cout << "Provide a sorted array of integers: " << std::endl;
    int N;
    std::cin >> N;
    std::vector<int> search_me;
    int curr;
    for (int i = 0; i < N; i++){
        std::cin >> curr;
        search_me.push_back(curr);
    }

    // User defines a value they want searched for.
    int find_me;
    std::cout << "Indicate the value you wish to find in the array. If it doesn't exist, the index of the value nearest (but less than) it will be provided: " << std::endl;
    std::cin >> find_me;

    // Call binary search.
    int winning_index = -1;
    recursiveBinarySearch(search_me,0,search_me.size(),find_me,winning_index);

    return winning_index;
}