#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include "graphTraversalHelper.hpp"

using namespace graphTraversal;

// Dijkstra's Algorithm for weighted graph traversal

// USER INPUTS:
//      start_node - starting node in the list
//      end_node - ending node in the list

// OUTPUTS:
//      Print out the pathway (series of nodes) that results in the shortest traversal
//      strategy for getting from start_node to end_node. As a bonus, print out the 
//      distance.

int main(){

    // User defines a graph which populates the vector of nodes.
    std::vector<Node> nodes = userDefinedGraph();

    // Query the user for a start node and end node.
    char start_node, end_node;
    std::cout << "Enter a start and end node (ex: A I): " << std::endl;
    std::cin >> start_node >> end_node;

    // Run Dijkstra's method.
    graphTraversal::runBFS_dijkstra(start_node, end_node, nodes);

    return 0;
}