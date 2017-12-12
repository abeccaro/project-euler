//
// Created by Alex Beccaro on 12/12/17.
//

#include "InputUtilities.h"
#include <fstream>
#include <sstream>

using namespace std;

namespace input_utilities {
    vector<int> readInts(string filename) {
        vector<int> numbers;
        ifstream file(filename);

        int n;
        while (file >> n)
            numbers.push_back(n);

        file.close();

        return numbers;
    }

    vector<vector<int>> readIntMatrix(string filename) {
        vector<vector<int>> matrix;
        ifstream file(filename);

        string line;
        while(getline(file, line)) {
            vector<int> row;
            stringstream lineStream(line);

            int n;
            while(lineStream >> n)
                row.push_back(n);

            matrix.push_back(row);
        }

        file.close();

        return matrix;
    }
}