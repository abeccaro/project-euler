//
// Created by Alex Beccaro on 16/12/17.
//

#include <iostream>
#include <vector>

using namespace std;
using namespace chrono;

/**
 * Finds the length of the collatz chain starting from n. It uses a vector for memoization.
 * @param n The starting number
 * @param memory The vector with already calculated lengths
 * @return The length of the chain
 */
unsigned long collatzLength(unsigned long n, const vector<unsigned long>& memory) {
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
    const unsigned long UPPER_BOUND = 1000000;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    unsigned long maxLength = 0;
    unsigned long maxLengthStart = 0;
    vector<unsigned long> memory(UPPER_BOUND);

    for (unsigned long i = 1; i < UPPER_BOUND; i++) {
        unsigned long length = collatzLength(i, memory);
        memory[i] = length;
        if (length > maxLength) {
            maxLength = length;
            maxLengthStart = i;
        }
    }

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The starting number, under " << UPPER_BOUND << ", that produces the longest chain is " << maxLengthStart << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}