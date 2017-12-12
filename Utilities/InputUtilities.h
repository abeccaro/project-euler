//
// Created by Alex Beccaro on 12/12/17.
//
#ifndef PROJECT_EULER_INPUTUTILITIES_H
#define PROJECT_EULER_INPUTUTILITIES_H

#endif //PROJECT_EULER_INPUTUTILITIES_H

#include <vector>
#include <string>

using namespace std;

namespace input_utilities {
    const string projectPath = "/Users/Becks/Programmazione/project-euler/";

    /**
     * Reads a vector of ints from specified file.
     * @param filename The path of input file
     * @return the vector of ints
     */
    vector<int> readInts(string filename);

    /**
     * Reads a matrix of ints from specified file.
     * @param filename The path of input file
     * @return The matrix of ints
     */
    vector<vector<int>> readIntMatrix(string filename);
}
