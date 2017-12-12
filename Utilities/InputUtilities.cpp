//
// Created by Alex Beccaro on 12/12/17.
//

#include "InputUtilities.h"
#include <fstream>

using namespace std;

namespace input_utilities {
    vector<int> readInts(string filename) {
        vector<int> numbers;
        ifstream file(filename);

        int n;
        while (file >> n)
            numbers.push_back(n);

        return numbers;
    }
}