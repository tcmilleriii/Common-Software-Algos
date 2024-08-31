#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

// KD Tree algorithm. This algorithm should enable swift search of a graph trees. My intention for this algorithm
// will be for effective use to identify closest points in 3D point clouds. The point cloud data should be stored
// and operable upon using an input style std::vector<std::vector<double> >.

int main(){

    // This example case will involve user input of a known point in space, then finding its closest point
    // using my kd-tree technique.
    // INPUT FORMAT:

    //         N        <-- N indicates number of rows
    //      x1 y1 z1    |
    //      x2 y2 z2    |
    //         .        | <-- raw data
    //         .        |
    //      xn yn zn    |

    std::cout << "Please input a point cloud:" << std::endl;
    int N;
    std::cin >> N;
    std::vector<std::vector<double> > point_cloud;
    for (int i = 0; i < N; i++){
        // Grab data, store into point_cloud.
        std::vector<double> curr_point= {};
        for (int j = 0; j < 3; j++){
            double curr_val;
            std::cin >> curr_val;
            curr_point.push_back(curr_val);
        }
        point_cloud.push_back(curr_point);
    }

    // Move on and request user inputs a single 3D point now in space. This will be the point 
    // that we execute our KD tree on to find the point in the cloud with nearest proximity.

    return 0;
}