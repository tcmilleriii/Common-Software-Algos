#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

// Binary Sort Algorithm template (for use with different variable types).

// Template defined here for use with different vector types (ex: integers, doubles, etc.)
// T1 usually a std::vector<some_variable_type> (search_me)
// T2 represents first value of current recursion
// T3 represents final index of current recursion
// T4 usually an value in the vector (find_me) - must be same variable type as T1 types
// T5 usually an integer (index of found value)
template<typename T1, typename T2, typename T3, typename T4, typename T5>
void recursiveBinarySearch(T1 search_me, T2 first, T3 last, T4 find_me, T5& winning_index){

    // Get middle.
    auto middle = floor((first + last) / 2);
    
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