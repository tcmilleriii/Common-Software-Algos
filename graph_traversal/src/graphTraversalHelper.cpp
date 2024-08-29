#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include "graphTraversalHelper.hpp"

namespace graphTraversal{

    // GRAPH TRAVERSAL FUNCTIONS:
    //      - runDFS: runs a depth first search, indicating via boolean if start_node and end_node are connected.
    //      - runBFS: runs a breadth first search, indicating via boolean if start_node and end_node are connected.
    //      - runBFS_dijkstra: runs a weighted breadth first search, whereby the fastest path between start_node and end node is determined.

    // HELPER FUNCTIONS:
    //      - findNodeInNodesList: searches the vector containing all node data and determines the index of the searched node.
    //      - userDefinedGraph: queries the user to input a graph of interconnected nodes. By default, user should provide weights (distances)
    //        between nodes, although this information is only relevant to weighted graph traversal methodologies.
    //      - calculateDistance: determines the distance between two nodes. 
    //      - updateLogs: updates the two hash maps that contain information for: current shortest overall distance to any node (from starting node) 
    //        and the current pathway between ndes.


    // ---------------------------- GRAPH TRAVERSAL FUNCTIONS -----------------------------------
    
    bool runBFS(char start_node, char end_node, std::vector<Node> nodes){

        // Initialize visited and queued lists.
        std::vector<char> queued;
        std::vector<char> visited;

        // Determine if starting node even exists in the tree. Error out if not since we have
        // nothing to search.
        int starting_index = findNodeInNodesList(nodes,start_node);
        if (starting_index == nodes.size() + 1){
            std::cout << "You didn't even give a starting node that exists in the tree." << std::endl;
            return false;
        } else {
            queued.push_back(nodes[starting_index].getThisNode());
        }

        // Iterate through.
        while (!queued.empty()){

            // Find index in the nodes list for the current node from our queue.
            int curr_index = findNodeInNodesList(nodes,queued[0]);

            // Add the connected nodes (those connected to curr node) to queue. Only add un-visited nodes.
            for (int i = 0; i < nodes[curr_index].getConnectedNodes().size(); i++){
                if (std::find(visited.begin(),visited.end(),nodes[curr_index].getConnectedNodes()[i]) == visited.end()){
                    queued.push_back(nodes[curr_index].getConnectedNodes()[i]);
                }
            }

            // Clean out the node who's connections we just put into the queue.
            visited.push_back(nodes[curr_index].getThisNode());
            queued.erase(std::remove(queued.begin(),queued.end(),nodes[curr_index].getThisNode()),queued.end());

        }

        // Verify that the end_node exists within the visited list. If not, there exists no connection between start_node 
        // and end_node.
        if (std::find(visited.begin(),visited.end(),end_node) != visited.end()){
            return true;
        }


        return false;
    }

    void runBFS_dijkstra(char start_node, char end_node, std::vector<Node> nodes){

        // Initialize visited and queued lists.
        std::vector<char> queued;
        std::vector<char> visited;
        std::vector<double> node_costs;

        // More initializations.
        double best_option = 0;
        char next_node;
        std::map<char,double>::iterator it;

        // Determine if starting node even exists in the tree. Error out if not since we have
        // nothing to search.
        int starting_index = findNodeInNodesList(nodes,start_node);
        if (starting_index == nodes.size() + 1){
            std::cout << "You didn't even give a starting node that exists in the tree." << std::endl;
            return;
        } else {
            queued.push_back(nodes[starting_index].getThisNode());
        }

        // Initialize a map containing the distances to all nodes. Preset all but starting node to a negative (impossible) distance.
        std::map<char,double> node_distances;
        for (int i = 0; i < nodes.size(); i++){
            if (i == starting_index){
                node_distances.insert({nodes[i].getThisNode(), 0});
            } 
            else {
                node_distances.insert({nodes[i].getThisNode(), -1});
            }
        }

        // Initialize a map containing all nodes and the node we used to get there.
        std::map<char, char> node_path;
        for (int i = 0; i < nodes.size(); i++){
            node_path.insert({nodes[i].getThisNode(), '0'});
        }

        // Find index in the nodes list for the current node from our queue.
        int curr_index = findNodeInNodesList(nodes,queued[0]);

        // Iterate through. Note that Dijkstra's respects node weights. We don't stop until we land on our
        // Desired endpoint, at which point we've done the job.
        while (queued[0] != end_node){

            // Add the connected nodes (those connected to curr node) to queue. Only add un-visited nodes.
            for (int i = 0; i < nodes[curr_index].getConnectedNodes().size(); i++){
                if (std::find(visited.begin(),visited.end(),nodes[curr_index].getConnectedNodes()[i]) == visited.end()){
                    queued.push_back(nodes[curr_index].getConnectedNodes()[i]);
                }
            }            
            
            // Update the distance logs and pathways logs. Whatever our current node is is where we're updating with 
            // respect to.
            updateLogs(node_distances, node_path,nodes,curr_index);

            // Update visited.
            visited.push_back(nodes[curr_index].getThisNode());

            // We select next node - always an unexplored node that has the smallest weight.
            it = node_distances.begin();
            while(it != node_distances.end()){
                if ((std::find(visited.begin(),visited.end(),it->first) == visited.end()) && (it->second > 0)){
                    if ((best_option == 0) || ((it->second < best_option) && (best_option > 0))){
                        next_node = it->first;
                        best_option = it->second;
                    }
                }
                it++;
            }

            // Erase current node from queue and migrate the targeted next node to the top of the queue.
            queued.erase(std::remove(queued.begin(),queued.end(),nodes[curr_index].getThisNode()));
            curr_index = findNodeInNodesList(nodes,next_node);
            queued.erase(std::remove(queued.begin(),queued.end(),nodes[curr_index].getThisNode()));
            queued.insert(queued.begin(),next_node);
        }

    }

    bool runDFS(char start_node, char end_node, std::vector<Node> nodes){

        // Initialize visited and stacked lists.
        std::vector<char> stacked;
        std::vector<char> visited;

        // Determine if starting node even exists in the tree. Error out if not since we have
        // nothing to search.
        int starting_index = findNodeInNodesList(nodes,start_node);
        if (starting_index == nodes.size() + 1){
            std::cout << "You didn't even give a starting node that exists in the tree." << std::endl;
            return false;
        } else {
            stacked.push_back(nodes[starting_index].getThisNode());
            for (int i = 0; i < nodes[starting_index].getConnectedNodes().size(); i++){
                if (std::find(visited.begin(),visited.end(),nodes[starting_index].getConnectedNodes()[i]) == visited.end()){
                    stacked.push_back(nodes[starting_index].getConnectedNodes()[i]);
                }
            }
            visited.push_back(nodes[starting_index].getThisNode());
            stacked.erase(std::remove(stacked.begin(),stacked.end(),nodes[starting_index].getThisNode()),stacked.end());
        }

        // Now begin proper loop.
        while (!stacked.empty()){

            // Find index in the nodes list for the current node from our queue.
            int curr_index = findNodeInNodesList(nodes,stacked[0]);

            // Pop this current index from the stack (done early in DFS).
            visited.push_back(nodes[curr_index].getThisNode());
            stacked.erase(std::remove(stacked.begin(),stacked.end(),nodes[curr_index].getThisNode()),stacked.end());

            // Add the child nodes to the queue. New adds must be in a 'depth first' fashion.
            for (int i = 0; i < nodes[curr_index].getConnectedNodes().size(); i++){
                if ((std::find(visited.begin(),visited.end(),nodes[curr_index].getConnectedNodes()[i]) == visited.end()) &&
                    (std::find(stacked.begin(),stacked.end(),nodes[curr_index].getConnectedNodes()[i]) == stacked.end())){
                    stacked.insert(stacked.begin(),nodes[curr_index].getConnectedNodes()[i]);
                }
            }

        }

        // Verify that the end_node exists within the visited list. If not, there exists no connection between start_node 
        // and end_node.
        if (std::find(visited.begin(),visited.end(),end_node) != visited.end()){
            return true;
        }

        return false;
    }

    // ---------------------------- HELPER FUNCTIONS -----------------------------------

    int findNodeInNodesList(std::vector<Node> nodes, char find_me){

        int index_of_interest = nodes.size() + 1; // Oversized

        // See if node we're searching for even exists. If so, return index.
        for (int i = 0; i < nodes.size(); i++){
            if (nodes[i].getThisNode() == find_me){
                index_of_interest = i;
                break;
            }
        }

        return index_of_interest;
    }

    std::vector<Node> userDefinedGraph(){

        // INPUT FORMAT:
        // <N>
        // <ID, #connections, x, y, z, n1, n1c1, n1c2, n1c3...>
        // <ID, #connections, x, y, z, n2, n2c1, n2c2, n2c3...>
        // .
        // .
        // .
        // <#, nN, nNc1, nNc2, nNc3...>

        // Sample input:
        // 9
        // A 3 0 0 0 B F G
        // B 2 -2 -1 0 A C
        // C 3 -2 -2 0 B D E
        // D 1 -3 -3 0 C
        // E 2 -1 -3 0 C F
        // F 2 -1 -1 0 E A
        // G 2 1 -1 0 A H
        // H 2 2 -2 0 G I
        // I 1 3 -3 0 H

        // Let the user define a graph themselves via terminal inputs.
        std::cout << "Input the graph scheme. Refer to graphTraversalHelper.cpp for input formatting: " << std::endl;
        int N;
        std::cin >> N;
        std::vector<Node> nodes;

        for (int i = 0; i < N; i++){

            // attack the current line.
            char my_id;
            int connected_count;
            std::cin >> my_id >> connected_count;

            // xyz.
            std::vector<int> xyz;
            for (int j = 0; j < 3; j++){
                int curr_pos;
                std::cin >> curr_pos;
                xyz.push_back(curr_pos);
            }
            
            // connected nodes.
            std::vector<char> my_conns;
            for (int j = 0; j < connected_count; j++){
                char curr_conn;
                std::cin >> curr_conn;
                my_conns.push_back(curr_conn);
            }

            // Now populate into vector of nodes.
            nodes.push_back(Node(xyz, my_conns, my_id));
        }

        return nodes;
    }

    double calculateDistance(char start_node, char end_node,std::vector<Node> nodes){

        // Determine indices of start node and end node in the nodes vector.
        int start_index = findNodeInNodesList(nodes, start_node);
        int end_index = findNodeInNodesList(nodes, end_node);

        double distance = 0;
        std::vector<int> differences = std::vector<int>(3); 
        for (int i = 0; i < 3; i++){
            differences[i] = nodes[end_index].getPosition()[i] - nodes[start_index].getPosition()[i];
            differences[i] = differences[i] * differences[i];
        }

        distance = sqrt(differences[0] + differences[1] + differences[2]);

        return distance;
    }

    void updateLogs(std::map<char,double> &node_distances, std::map<char,char> &node_path, std::vector<Node> nodes,int curr_index){

        // Use curr index to determine all connected nodes to the node we're currently sitting at. Update the distances and paths.
        char start_node = nodes[curr_index].getThisNode();
        for (int i = 0; i < nodes[curr_index].getConnectedNodes().size(); i++){

            // current destination node under scrutiny.
            char end_node = nodes[curr_index].getConnectedNodes()[i];

            // hang on to distance to destination node under srutiny.
            // This is the distance from curr_node to destination node PLUS whatever it took to reach where we are starting from.
            double temp_dist = calculateDistance(start_node, end_node, nodes) + node_distances.at(start_node);

            // If the distance to node under scrutiny is shortest, set that for distance and path.
            if (node_distances.at(end_node) >= 0){
                node_distances.at(end_node) = (temp_dist < node_distances.at(end_node)) ? temp_dist : node_distances.at(end_node);
                node_path.at(end_node) = (temp_dist < node_distances.at(end_node)) ? start_node : node_path.at(end_node);
            } 
            else{
                node_distances.at(end_node) = temp_dist;
                node_path.at(end_node) = start_node;
            }
        }
    }
}