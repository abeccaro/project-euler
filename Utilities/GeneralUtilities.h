//
// Created by Alex Beccaro on 11/12/17.
//
#ifndef PROJECT_EULER_GENERALUTILITIES_H
#define PROJECT_EULER_GENERALUTILITIES_H

#endif //PROJECT_EULER_GENERALUTILITIES_H

#include <vector>

using namespace std;

namespace GeneralUtilities {
    /**
     * Checks if given number is palindrome or not.
     * @param n The number to check
     * @return true if the number is palindrome, false otherwise
     */
    bool isPalindrome(int n);

    /**
     * Divides given number in a vector of ordered digits.
     * @param n The number to divide
     * @return The vector of ordered digits
     */
    vector<int> digits(int n);
}