//
// Created by Alex Beccaro on 08/01/18.
//

#include <iostream>
#include <primes.hpp>
#include <series/primes.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace generics;
using primes::is_prime;
using series::primes;

using numtype = unsigned long;

/**
 * Generates all masks with multiples of 3 elements out of n
 * @param size The size of the masks
 * @return The masks
 */
vector<vector<bool>> masks(unsigned long size) {
    vector<vector<bool>> v;

    if (size < 3)
        return v;

    v.emplace_back(vector<bool>{false, false, false});
    v.emplace_back(vector<bool>{false, false, true});
    v.emplace_back(vector<bool>{false, true, false});
    v.emplace_back(vector<bool>{false, true, true});
    v.emplace_back(vector<bool>{true, false, false});
    v.emplace_back(vector<bool>{true, false, true});
    v.emplace_back(vector<bool>{true, true, false});
    v.emplace_back(vector<bool>{true, true, true});

    while (size > 3) {
        vector<vector<bool>> v_true(v);
        for (vector<bool> &vec : v_true)
            vec.push_back(true);
        vector<vector<bool>> v_false(v);
        for (vector<bool> &vec : v_false)
            vec.push_back(false);

        v.clear();
        v.insert(v.end(), v_true.begin(), v_true.end());
        v.insert(v.end(), v_false.begin(), v_false.end());

        size--;
    }

    vector<vector<bool>> v_result;
    for (const vector<bool>& vec : v) {
        unsigned int sum = 0;
        for (const auto& b : vec)
            if (b)
                sum++;
        if (sum > 0 && sum % 3 == 0)
            v_result.push_back(vec);
    }

    return v_result;
}

/**
 * Creates the family of given number using given mask and returns its size. This assumes the required family size is 8
 * to improve efficiency
 * @param digs The digits of the number
 * @param mask The mask to use
 * @return The size of generated family
 */
unsigned long get_family_size(const vector<unsigned int>& digs, const vector<bool>& mask) {
    vector<numtype> family;

    for (unsigned int i = 0; i < 10; i++) {
        vector<unsigned int> member(digs.size());

        auto it = mask.begin();
        auto m_it = member.begin();
        for (const auto& d : digs) {
            if (d < 3)
                *m_it = (*it++) ? i : d;
            else
                *m_it = d;

            m_it++;
        }

        if (member[0] != 0) {
            auto number = from_digits<numtype>(member);
            if (is_prime(number))
                family.push_back(number);
        }
    }

    return family.size();
}

/**
 * Checks if given number has a family with at least 8 primes. This assumes the required family size is 8 to improve
 * efficiency
 * @param number The number to check
 * @return true if exists a family of number with at least 8 primes, false otherwise
 */
bool has_required_family(const numtype& number) {
    vector<unsigned int> digs = digits(number);

    unsigned long mask_size = count_if(digs.begin(), digs.end(), [](unsigned int d){return d < 3;});
    auto m = masks(mask_size);

    for (const auto& mask : m)
        if (get_family_size(digs, mask) >= 8)
            return true;
    return false;
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype LOWER_BOUND = 56003;  // given by problem

    timer::time_point start = timer::now();

    primes<numtype> p;
    numtype result = 0;

    for (const auto& prime : p) {
        if (prime < LOWER_BOUND)
            continue;

        if (has_required_family(prime)) {
            result = prime;
            break;
        }
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The smallest prime which, by replacing part of the number with the same digit, is part of an eight prime "
         << "value family is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}