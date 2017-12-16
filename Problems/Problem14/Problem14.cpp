//
// Created by Alex Beccaro on 16/12/17.
//

#include <iostream>
#include <vector>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;

using numtype = unsigned int;

/**
 * Finds the length of the collatz chain starting from n. It uses a vector for memoization.
 * @param n The starting number
 * @param memory The vector with already calculated lengths
 * @return The length of the chain
 */
numtype collatzLength(numtype n, const vector<numtype>& memory) {
    if (n == 1)
        return 1;

    if (memory.size() >= n && memory[n] != 0)
        return memory[n];

    if (n % 2 == 0)
        return 1 + collatzLength(n / 2, memory);
    return 1 + collatzLength(3 * n + 1, memory);
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype UPPER_BOUND = 1000000;

    timer::time_point start = timer::now();

    numtype maxLength = 0;
    numtype maxLengthStart = 0;
    vector<numtype> memory(UPPER_BOUND);

    for (numtype i = 1; i < UPPER_BOUND; i++) {
        numtype length = collatzLength(i, memory);
        memory[i] = length;
        if (length > maxLength) {
            maxLength = length;
            maxLengthStart = i;
        }
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The starting number, under " << UPPER_BOUND << ", that produces the longest chain is " << maxLengthStart << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}