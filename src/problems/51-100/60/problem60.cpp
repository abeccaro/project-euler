//
// Created by Alex Beccaro on 11/01/18.
//

#include "problem60.hpp"
#include "primes.hpp"
#include "generics.hpp"

using std::vector;

using primes::is_prime;
using primes::primes_up_to;
using generics::digits;
using generics::from_digits;

namespace problems {

    bool problem60::add_next(const vector<uint32_t>& p, vector<uint32_t>& n, uint32_t lb) {
        for (const auto &prime : p) {
            if (prime <= lb)
                continue;

            bool ok = true;
            for (const auto &num : n) {
                auto p_digs = digits(prime);
                auto n_digs = digits(num);
                uint32_t p_size = p_digs.size();

                p_digs.insert(p_digs.end(), n_digs.begin(), n_digs.end());
                if (!is_prime(from_digits<uint64_t>(p_digs))) {
                    ok = false;
                    break;
                }

                n_digs.insert(n_digs.end(), p_digs.begin(), p_digs.begin() + p_size);
                if (!is_prime(from_digits<uint64_t>(n_digs))) {
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

    vector<uint32_t> problem60::find_tuple(uint32_t ub, uint32_t size) {
        vector<uint32_t> p = primes_up_to(ub);
        vector<uint32_t> sol;
        uint32_t lower_bound = 2;

        while (sol.size() < size) {
            bool added = add_next(p, sol, lower_bound);
            lower_bound = sol.back();
            if (!added)
                sol.pop_back();
        }

        return sol;
    }

    uint32_t problem60::solve(uint32_t n) {
        const uint32_t ub = 10000; // empirical bound for n = 5

        auto sol = find_tuple(ub, n);

        uint32_t result = 0;
        for (const auto &p : sol)
            result += p;
        return result;
    }
}