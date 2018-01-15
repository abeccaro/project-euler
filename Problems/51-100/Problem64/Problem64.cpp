//
// Created by Alex Beccaro on 14/01/18.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype N = 10000;

    timer::time_point start = timer::now();

    numtype result = 0;

    for (numtype i = 2; i <= N; i++) {
        vector<numtype> period;

        auto a_0 = (numtype) sqrt(i);
        numtype a = a_0;
        numtype m = 0;
        numtype d = 1;

        if (a * a == i) // perfect square
            continue;

        do {
            m = d * a - m;
            d = (i - m * m) / d;
            a = (a_0 + m) / d;

            period.push_back(a);
        } while(period.back() != a_0 * 2);

        if (period.size() % 2 == 1)
            result++;
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The number of continued fractions of √N for N ≤ " << N << " that have an odd period is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}