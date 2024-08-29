#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

namespace graphTraversal{

    class Node{

        private:
            // Variables.
            std::vector<char> _connected_nodes;
            std::vector<int> _position = std::vector<int>(3);
            char _this_node;
            

            // Setters (kept within the class's declaration in header).
            void setPosition(std::vector<int> my_position){
                _position = my_position; 
            }

            void setConnections(std::vector<char> my_connections){
                _connected_nodes = my_connections;
            }        

            void setThisNode(char letter){
                _this_node = letter;
            }

        public:

            // Constructors.
            Node(std::vector<int> my_position, std::vector<char> my_connections, char letter){

            // Set my position.
            setPosition(my_position);

            // Set my connections.
            setConnections(my_connections);

            // Set my node ID.
            setThisNode(letter);
            }

            // Getters.
            char getThisNode(){ return _this_node; };
            std::vector<char> getConnectedNodes(){ return _connected_nodes; };
            std::vector<int> getPosition(){return _position; };

    };

    // GRAPH TRAVERSAL FUNCTIONS.
    bool runBFS(char start_node, char end_node, std::vector<Node> nodes);
    void runBFS_dijkstra(char start_node, char end_node, std::vector<Node> nodes);
    bool runDFS(char start_node, char end_node, std::vector<Node> nodes);
    int findNodeInNodesList(std::vector<Node> nodes, char find_me);
    // HELPER FUNCTIONS.
    std::vector<graphTraversal::Node> userDefinedGraph();
    double calculateDistance(char start_node, char end_node,std::vector<Node> nodes);
    void updateLogs(std::map<char,double> &node_distances, std::map<char,char> &node_path, std::vector<Node> nodes,int curr_index);

    

}