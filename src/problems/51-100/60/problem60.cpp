//
// Created by Alex Beccaro on 11/01/18.
//

#include "problem60.hpp"
#include <primes.hpp>
#include <generics.hpp>

using primes::is_prime;
using primes::primes_up_to;
using generics::digits;
using generics::from_digits;

using ulong = unsigned long;

namespace problems {

    bool problem60::add_next(const vector<uint>& p, vector<uint>& n, uint lb) {
        for (const auto &prime : p) {
            if (prime <= lb)
                continue;

            bool ok = true;
            for (const auto &num : n) {
                auto p_digs = digits(prime);
                auto n_digs = digits(num);
                uint p_size = p_digs.size();

                p_digs.insert(p_digs.end(), n_digs.begin(), n_digs.end());
                if (!is_prime(from_digits<ulong>(p_digs))) {
                    ok = false;
                    break;
                }

                n_digs.insert(n_digs.end(), p_digs.begin(), p_digs.begin() + p_size);
                if (!is_prime(from_digits<ulong>(n_digs))) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                n.push_back(prime);
                return true;
            }
        }

        return false;
    }

    vector<uint> problem60::find_tuple(uint ub, uint size) {
        vector<uint> p = primes_up_to(ub);
        vector<uint> sol;
        uint lower_bound = 2;

        while (sol.size() < size) {
            bool added = add_next(p, sol, lower_bound);
            lower_bound = sol.back();
            if (!added)
                sol.pop_back();
        }

        return sol;
    }

    uint problem60::solve(uint n) {
        const uint UPPER_BOUND = 10000; // empirical bound for n = 5

        auto sol = find_tuple(UPPER_BOUND, n);

        uint result = 0;
        for (const auto &p : sol)
            result += p;
        return result;
    }
}