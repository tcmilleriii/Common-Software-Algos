# Quick Sort Algorithm
A divide and conquer algorithm that picks an element in an array as a pivot and partitions around the picked pivot by placing the pivot in its correct position in the sorted array.

## Usage
### Prerequisites
You will need:
- a modern C/C++ compiler
- CMake 3.27.9+ installed (on a Mac, run `brew install cmake`)


### Building the Project
First we need to check out the git repo, then build:
```
mkdir ~/workspace  
cd ~/workspace  
git clone https://github.com/tcmilleriii/Common-Software-Algos.git  
cd quicksort_algo/
cd build  
cmake ..  
make
```

### Running the Algorithm
Now, with the executable ready, we can simply run the main.cpp script with the following command:
`./main`

You will be prompted to enter both an unsorted array as well as an array size. 

### Example 
After the `./main` command has been entered into the terminal, user will be prompted to enter an example data set. An example data array of size N=5 values is provided:
```
5  
5 4 3 2 1
```

The script will then sort this array. 