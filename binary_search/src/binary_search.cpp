#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

// The following script is a binary search algorithm. THe function takes in an array of integers
// (vector from standard library). Array should be a sorted list.

// User defines (via std::cin) an array of integers.

// USER INPUT FORMAT:
// N
// x1 x2 x3 ... xN

// WHERE:
// N = integer indicating number of inputs in the array (sorted already, smallest to biggest).
// x = each value in the array, from first to Nth.

// OUTPUT:
//  - Algorithm outputs the index at which the desired value exists.

void recursiveBinarySearch(std::vector<int> search_me, int first, int last, int find_me, int& winning_index){

    // Get middle.
    int middle = floor((first + last) / 2);
    
    // Check if the middle val is it.
    if (search_me[middle] == find_me) {
        winning_index = middle;
        return;
    }

    // Check if first = last (at this point we would've found it if it existed). One little logic loop in here
    // to handle the 'Price is Right' criteria of providing an index for the first number that's still below the
    // find_me value.
    if (first == last){
        if (find_me < search_me[first]){
            winning_index = first - 1;
        } else{
            winning_index = first;
        }
        return;
    }

    // Resize and recurse.
    if (find_me < search_me[middle]){
        recursiveBinarySearch(search_me,first,middle-1,find_me,winning_index);
    } else if (find_me > search_me[middle]){
        recursiveBinarySearch(search_me,middle+1,last,find_me,winning_index);
    }

    return;

}