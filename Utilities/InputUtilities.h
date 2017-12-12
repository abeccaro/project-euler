//
// Created by Alex Beccaro on 12/12/17.
//
#ifndef PROJECT_EULER_INPUTMANAGER_H
#define PROJECT_EULER_INPUTMANAGER_H

#endif //PROJECT_EULER_INPUTMANAGER_H

#include <vector>
#include <string>

using namespace std;

namespace input_utilities {
    const string projectPath = "/Users/Becks/Programmazione/project-euler/";

    /**
     * Reads an array of ints from specified file.
     * @param filename The path of input file
     * @return the vector of ints
     */
    vector<int> readInts(string filename);
}
