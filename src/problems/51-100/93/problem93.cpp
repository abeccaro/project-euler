//
// Created by Alex Beccaro on 01/03/18.
//

#include "problem93.hpp"
#include <generics.hpp>

using std::vector;
using std::map;
using std::set;
using std::string;

using generics::combinations;

namespace problems {
    vector<float> problem93::apply_operators_first(const vector<uint32_t>& digits, map<vector<uint32_t>, vector<float> >& m) {
        vector<float> numbers;

        vector<uint32_t> end(digits.size() - 1);
        std::copy(digits.begin() + 1, digits.end(), end.begin());
        uint32_t first = digits.front();

        if (m.find(end) == m.end())
            apply_operators(end, m);

        for (float n : m[end]) {
            numbers.push_back(first + n);
            numbers.push_back(first - n);
            numbers.push_back(first * n);
            if (n != 0)
                numbers.push_back(first / n);
        }

        return numbers;
    }

    vector<float> problem93::apply_operators_last(const vector<uint32_t>& digits, map<vector<uint32_t>, vector<float> >& m) {
        vector<float> numbers;

        vector<uint32_t> start(digits);
        start.resize(start.size() - 1);
        uint32_t last = digits.back();

        if (m.find(start) == m.end())
            apply_operators(start, m);

        for (float n : m[start]) {
            numbers.push_back(n + last);
            numbers.push_back(n - last);
            numbers.push_back(n * last);
            if (last != 0)
                numbers.push_back(n / last);
        }

        return numbers;
    }

    vector<float> problem93::apply_operators(const vector<uint32_t>& digits, map<vector<uint32_t>, vector<float> >& m) {
        if (m.find(digits) != m.end())
            return m[digits];

        if (digits.size() == 1) {
            m[digits] = {(float) digits.front()};
            return m[digits];
        }

        vector<float> numbers = apply_operators_last(digits, m);
        vector<float> sub = apply_operators_first(digits, m);
        numbers.insert(numbers.end(), sub.begin(), sub.end());

        m[digits] = numbers;
        return numbers;
    }

    uint32_t problem93::consecutive_int_length(const set<uint32_t>& numbers) {
        uint32_t length = 0;

        for (uint32_t i = 1; ; i++) {
            if (numbers.find(i) == numbers.end())
                break;
            length++;
        }

        return length;
    }

    string problem93::solve() {
        const vector<uint32_t> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        map<vector<uint32_t>, vector<float> > m;
        uint32_t max_length = 0;
        vector<uint32_t> result;

        for (vector<uint32_t> digs : combinations(digits, 4)) {
            set<uint32_t> numbers;

            for (uint32_t p = 0; p < 24; p++) {
                vector<float> res = apply_operators(digs, m);

                for (float n : res)
                    if (n == (uint32_t) n)
                    numbers.insert((uint32_t) n);

                std::next_permutation(digs.begin(), digs.end());
            }

            uint32_t length = consecutive_int_length(numbers);

            if (length > max_length) {
                max_length = length;
                result = digs;
            }
        }

        string s;
        for (uint32_t d : result)
            s += std::to_string(d);

        return s;
    }
}