//
// Created by Alex Beccaro on 14/01/18.
//

#include <iostream>
#include <generics.hpp>
#include <map>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace generics;

using numtype = unsigned long;
using uint = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype N = 5; // numbers of cubes permutations

    timer::time_point start = timer::now();

    numtype result = 0;
    map<vector<uint>, vector<numtype>> m;

    for (numtype i = 1; result == 0; i++) {
        numtype n = i * i * i;
        vector<uint> digs = digits(n);
        sort(digs.begin(), digs.end());

        vector<numtype>& cubes = m[digs];
        cubes.push_back(n);

        if (cubes.size() >= N)
            result = cubes.front();
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The smallest cube for which exactly five permutations of its digits are cube is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}