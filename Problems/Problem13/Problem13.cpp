//
// Created by Alex Beccaro on 15/12/17.
//

#include <iostream>
#include "../../Utilities/InputUtilities.h"

using namespace std;
using namespace chrono;
using namespace input_utilities;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const int DIGITS = 50;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    vector<vector<int>> numbers = readIntMatrix(projectPath + "Problems/Problem13/input.txt");

    int remainder = 0;
    vector<int> result(DIGITS);

    for (int i = DIGITS - 1; i >= 0; i--) {
        int  sum = remainder;

        for (vector<int> n : numbers)
            sum += n[i];

        result[i] = sum % 10;
        remainder = sum / 10;
    }

    while (remainder > 0) {
        result.insert(result.begin(), remainder % 10);
        remainder /= 10;
    }

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The first 10 digits of the sum are ";
    for (int i = 0; i < 10; i++)
        cout << result[i];
    cout << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}