//
// Created by Alex Beccaro on 13/03/18.
//

#include "problem98.hpp"
#include <input.hpp>
#include <series/figurate_number.hpp>

using std::vector;
using std::string;
using std::pair;
using std::to_string;

using input::read_vector;
using input::problems_folder;
using series::figurate_number;

namespace problems {
    uint32_t problem98::match(pair<string, string> p, uint32_t square) {
        string s = to_string(square);

        for (uint32_t j = 0; j < s.size(); j++) {
            if (isdigit(p.first[j]))
                continue;

            if (find(p.first.begin(), p.first.begin() + j, s[j]) < p.first.begin() + j)
                return 0;

            replace(p.second.begin(), p.second.end(), p.first[j], s[j]);
            replace(p.first.begin(), p.first.end(), p.first[j], s[j]);
        }

        if (any_of(p.first.begin(), p.first.end(), isalpha) || p.second[0] == '0')
            return 0;

        return strtoul(p.second.c_str(), NULL, 0);
    }

    uint32_t problem98::max_pair_square(const pair<string, string>& p, const vector<uint32_t>& squares) {
        uint32_t max = 0;

        for (auto i = squares.begin(); i < squares.end(); i++) {
            uint32_t n2 = match(p, *i);

            if (n2 == 0 || find(squares.begin(), squares.end(), n2) == squares.end())
                continue;

            uint32_t n1 = strtoul(p.first.c_str(), NULL, 0);
            if (n1 > n2 && n1 > max)
                max = n1;
            else if (n2 > max)
                max = n2;
        }

        return max;
    }

    bool problem98::is_anagram_pair(const string& w1, const string& w2) {
        if (w1.size() != w2.size())
            return false;

        return is_permutation(w1.begin(), w1.end(), w2.begin());
    }

    uint32_t problem98::solve() {
        vector<string> words = read_vector<string>(problems_folder + "51-100/98/input.txt");
        vector<pair<string, string>> pairs;
        figurate_number<uint32_t> squares(4);

        // getting anagram pairs
        for (auto i = words.begin(); i < words.end(); i++)
            for (auto j = i + 1; j < words.end(); j++)
                if (is_anagram_pair(*i, *j))
                    pairs.emplace_back(*i, *j);

        // sorting by length desc
        sort(pairs.begin(), pairs.end(), [](const pair<string, string>& lhs, const pair<string, string>& rhs) {
            return lhs.first.size() > rhs.first.size();
        });

        uint32_t result = 0;
        for (const auto& p : pairs) {
            // get squares of the same length of words in p
            uint32_t l = p.first.size();
            uint32_t lb = pow(10, l - 1);
            uint32_t ub = pow(10, l);
            vector<uint32_t> ss = squares.get_while(
                    [ub](uint32_t s) { return s < ub; },
                    [lb](uint32_t s) { return s >= lb; }
            );

            // find max square in pair p
            uint32_t max_s = max_pair_square(p, ss);

            // store max square found as result
            if (max_s > result)
                result = max_s;
        }

        return result;
    }
}