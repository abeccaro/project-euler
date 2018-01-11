//
// Created by Alex Beccaro on 17/12/17.
//

#include <iostream>
#include <input.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace input;

using numtype = unsigned long;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    timer::time_point start = timer::now();

    vector<string> names = read_vector<string>(PROJECT_PATH + "Problems/1-50/Problem22/input.txt");
    sort(names.begin(), names.end());

    numtype sum = 0;
    for (numtype i = 0; i < names.size(); i++) {
        numtype score = 0;
        for (const auto& letter : names[i])
            score += letter - 'A' + 1;
        sum += score * (i + 1);
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of all the scores of given names is " << sum << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}