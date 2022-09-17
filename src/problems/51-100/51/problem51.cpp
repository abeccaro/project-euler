//
// Created by Alex Beccaro on 08/01/18.
//

#include "problem51.hpp"
#include <primes.hpp>
#include <series/primes.hpp>
#include <generics.hpp>

using std::vector;
using generics::digits;
using generics::from_digits;
using primes::is_prime;

namespace problems {
    vector<vector<bool>> problem51::masks(uint32_t size) {
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
        for (const vector<bool> &vec : v) {
            uint32_t sum = 0;
            for (const auto &b : vec)
                if (b)
                    sum++;
            if (sum > 0 && sum % 3 == 0)
                v_result.push_back(vec);
        }

        return v_result;
    }

    uint32_t problem51::get_family_size(const vector<uint32_t>& digs, const vector<bool>& mask) {
        vector<uint32_t> family;

        for (uint32_t i = 0; i < 10; i++) {
            vector<uint32_t> member(digs.size());

            auto it = mask.begin();
            auto m_it = member.begin();
            for (const auto &d : digs) {
                if (d < 3)
                    *m_it = (*it++) ? i : d;
                else
                    *m_it = d;

                m_it++;
            }

            if (member[0] != 0) {
                auto number = from_digits<uint64_t>(member);
                if (is_prime(number))
                    family.push_back(number);
            }
        }

        return family.size();
    }

    bool problem51::has_required_family(const uint32_t& number) {
        vector<uint32_t> digs = digits(number);

        uint32_t mask_size = count_if(digs.begin(), digs.end(), [](uint32_t d) { return d < 3; });
        auto m = masks(mask_size);

        for (const auto &mask : m)
            if (get_family_size(digs, mask) >= 8)
                return true;
        return false;
    }

    uint32_t problem51::solve() {
        const uint32_t lb = 56003;  // lower bound given by problem

        series::primes<uint64_t> p;
        for (const auto &prime : p)
            if (prime >= lb && has_required_family(prime))
                return (uint32_t) prime;

        return 0;
    }
}