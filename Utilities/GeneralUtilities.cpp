//
// Created by Alex Beccaro on 11/12/17.
//

#include "GeneralUtilities.h"
#include <algorithm>

using namespace std;

namespace GeneralUtilities {
    bool isPalindrome(int n) {
        vector<int> dig = digits(n);
        vector<int> reversedDig(dig.size());

        reverse_copy(dig.begin(), dig.end(), reversedDig.begin());

        return dig == reversedDig;
    }

    vector<int> digits(int n) {
        vector<int> digits;

        while (n > 9) {
            int d = n % 10;
            digits.push_back(d);
            n /= 10;
        }
        digits.push_back(n);

        reverse(digits.begin(), digits.end());
        return digits;
    }
}