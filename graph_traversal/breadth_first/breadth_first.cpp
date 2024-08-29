#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include "graphTraversalHelper.hpp"

using namespace graphTraversal;

// Breadth First Search Algorithm

// V1.0 - a predefined linked list is shown below. For now working with that. 
// Would be nice to enable the user to input data and have a function that 
// constructs nodes based off their inputs.

// USER INPUTS:
//      start_node - starting node in the list
//      end_node - ending node in the list

// OUTPUTS:
//      print whether there exists a path between the start node and the ending node.

int main(){

    std::vector<Node> nodes = userDefinedGraph();

    // Query the user for a start node and end node.
    char start_node, end_node;
    std::cout << "Enter a start and end node (ex: A I): " << std::endl;
    std::cin >> start_node >> end_node;

    // Run BFS. Boolean output of whether a connection b/w start node and end node existed.
    bool exists_connection = runBFS(start_node, end_node, nodes);

    if (exists_connection){
        std::cout << "You dun it. Congration." << std::endl;
    } else {
        std::cout << "Couldn't find the connection." << std::endl;
    }

    return 0;
}
