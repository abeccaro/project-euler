//
// Created by Alex Beccaro on 07/01/18.
//

#include <iostream>
#include <input.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace input;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    timer::time_point start = timer::now();

    numtype result = 0;
    vector<string> words = read_vector<string>(PROJECT_PATH + "Problems/1-50/Problem42/input.txt");

    for (const auto& word : words) {
        numtype score = 0;
        for (const auto& letter : word)
            score += letter - 'A' + 1;

        // x is triangular iff 8x + 1 is a square
        numtype n = 8 * score + 1;
        auto root = (numtype) sqrt(n);
        if (root * root == n)
            result++;
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The number of triangular words in input file is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}