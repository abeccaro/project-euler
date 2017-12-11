//
// Created by Alex Beccaro on 11/12/17.
//

#include <iostream>
#include "../../Utilities/GeneralUtilities.h"

using namespace std;
using namespace chrono;
using namespace GeneralUtilities;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    high_resolution_clock::time_point start = high_resolution_clock::now();

    int largestPalindrome = 0;

    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            int n = i * j;
            if (n > largestPalindrome && isPalindrome(n))
                largestPalindrome = n;
        }
    }

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The largest palindrome made from the product of two 3-digit numbers is " << largestPalindrome << endl;
    cout << "Calculation took " << time << " seconds" << endl;

    return 0;
}