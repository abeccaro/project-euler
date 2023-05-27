//
// Created by Alex Beccaro on 22/05/2023.
//

#include "generics.hpp"
#include "problem175.hpp"
#include "ranges"
#include "vector"


using generics::continued_fraction;
using std::ranges::reverse_view;
using std::reverse;
using std::string;
using std::stringstream;
using std::vector;

namespace problems {
    // The sequence of f(n)/f(n-1) enumerates all the rational numbers in a way similar to Calkin–Wilf sequence.
    // More precisely it can be obtained by reading each level of the Calkin–Wilf tree from right to left.
    // By using the continued fraction for given rational we can calculate the index in the sequence as described in
    // wikipedia here: https://en.wikipedia.org/wiki/Calkin%E2%80%93Wilf_tree#Breadth_first_traversal.
    string problem175::solve(uint32_t numerator, uint32_t denominator) {
        // calculate continued fraction of inverse (because of reading from right to left)
        vector<uint32_t> cf = continued_fraction(denominator, numerator);

        // Adjust the continued fraction representation if necessary
        if (cf.size() % 2 == 0) {
            cf.back()--;
            cf.push_back(1);
        }

        // Build Shortened Binary Expansion representation
        stringstream ss;
        for (const auto& it : reverse_view(cf))
            ss << it << ",";
        string result = ss.str();
        result.erase(result.size() - (result.ends_with(",0,") ? 3 : 1));

        return result;
    }
}