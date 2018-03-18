//
// Created by Alex Beccaro on 28/02/18.
//

#include "problem89.hpp"
#include <input.hpp>

using std::vector;
using std::string;
using std::map;

using input::read_vector;
using input::problems_folder;

namespace problems {
    map<char, uint> problem89::letterValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };

    uint problem89::from_roman(const string& roman) {
        auto size = roman.size();

        if (size == 0)
            return 0;

        if (size == 1)
            return letterValues[roman.front()];

        uint v0 = letterValues[roman.front()];
        uint v1 = letterValues[roman[1]];

        if (v1 > v0)
            return v1 - v0 + from_roman(roman.substr(2, size - 2));

        return v0 + from_roman(roman.substr(1, size - 1));
    }

    string problem89::to_roman(uint n) {
        if (n >= 1000)
            return "M" + to_roman(n - 1000);
        if (n >= 900)
            return "CM" + to_roman(n - 900);
        if (n >= 500)
            return "D" + to_roman(n - 500);
        if (n >= 400)
            return "CD" + to_roman(n - 400);
        if (n >= 100)
            return "C" + to_roman(n - 100);
        if (n >= 90)
            return "XC" + to_roman(n - 90);
        if (n >= 50)
            return "L" + to_roman(n - 50);
        if (n >= 40)
            return "XL" + to_roman(n - 40);
        if (n >= 10)
            return "X" + to_roman(n - 10);
        if (n == 9)
            return "IX";
        if (n >= 5)
            return "V" + to_roman(n - 5);
        if (n == 4)
            return "IV";
        if (n >= 1)
            return "I" + to_roman(n - 1);
        return "";
    }

    uint problem89::solve() {
        uint result = 0;

        vector<string> in = read_vector<string>(problems_folder + "51-100/89/input.txt");
        for (string s : in)
            result += s.size() - to_roman(from_roman(s)).size();

        return result;
    }
}