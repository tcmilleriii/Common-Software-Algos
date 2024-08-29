#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include "graphTraversalHelper.hpp"

using namespace graphTraversal;

// Depth First Search Algorithm

// USER INPUTS:
//      start_node - starting node in the list
//      end_node - ending node in the list

// OUTPUTS:
//      print whether there exists a path between the start node and the ending node.

int main(){

    // User defines a graph which populates the vector of nodes.
    std::vector<Node> nodes = userDefinedGraph();

    // Query the user for a start node and end node.
    char start_node, end_node;
    std::cout << "Enter a start and end node (ex: A I): " << std::endl;
    std::cin >> start_node >> end_node;

    // Run DFS. Boolean output of whether a connection b/w start node and end node existed.
    bool exists_connection = runDFS(start_node, end_node, nodes);

    if (exists_connection){
        std::cout << "You dun it. Congration." << std::endl;
    } else {
        std::cout << "Couldn't find the connection." << std::endl;
    }

    return 0;
}