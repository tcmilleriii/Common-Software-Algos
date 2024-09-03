# Binary Search
From a sorted list, determine the index of the desired variable.

## Usage
### Prerequisites
You will need:
- a modern C/C++ compiler
- CMake 3.27.9+ installed (on a Mac, run `brew install cmake`)


### Building the Project
First we need to check out the git repo, then build:
>mkdir ~/workspace
>cd ~/workspace
>git clone https://github.com/tcmilleriii/Common-Software-Algos.git 
>cd build 
>cmake ..
>make

### Running the Binary Sort Algorithm
Now, with the executable ready, we can simply run the main.cpp script with the following command:
`./main`

You will be prompted to enter both a sorted array as well as a targeted variable within that array. The algorithm will return the index (0-based) of the desired number.

### Example 
After the `./main` command has been entered into the terminal, user will be prompted to enter an example data set. An example data set of N=5 values is provided:
>5 
>1 2 3 4 5

You are then prompted to indicate which number you'd like to find in the array, for example:
`4`

The script will then find the index of this number in the array, which in our example would be 3.