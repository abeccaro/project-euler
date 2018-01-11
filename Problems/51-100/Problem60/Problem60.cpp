//
// Created by Alex Beccaro on 11/01/18.
//

#include <iostream>
#include <primes.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace primes;
using namespace generics;

using numtype = unsigned int;

/**
 * Adds to n the first prime taken from p > lb that concatenated with any element of n in both ways gives a prime.
 * @param p The list of all primes
 * @param n The list of already present primes
 * @param lb The lower bound
 * @return true if a new element is added, false otherwise
 */
bool add_next(const vector<numtype>& p, vector<numtype>& n, const numtype& lb) {
    for (const auto& prime : p) {
        if (prime <= lb)
            continue;

        bool ok = true;
        for (const auto& num : n) {
            auto p_digs = digits(prime);
            auto n_digs = digits(num);
            numtype p_size = p_digs.size();

            p_digs.insert(p_digs.end(), n_digs.begin(), n_digs.end());
            if (!is_prime(from_digits<numtype>(p_digs))) {
                ok = false;
                break;
            }

            n_digs.insert(n_digs.end(), p_digs.begin(), p_digs.begin() + p_size);
            if (!is_prime(from_digits<numtype>(n_digs))) {
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

/**
 * Finds a quintuplet of primes that satisfy problem requirements.
 * @param ub The upper bound for primes
 * @return The quintuplet
 */
vector<numtype> find_quintuplet(const numtype& ub) {
    vector<numtype> p = primes_up_to(ub);
    vector<numtype> sol;
    numtype lower_bound = 2;

    while (sol.size() < 5) {
        bool added = add_next(p, sol, lower_bound);
        lower_bound = sol.back();
        if (!added)
            sol.pop_back();
    }

    return sol;
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype UPPER_BOUND = 10000; // empirical bound

    timer::time_point start = timer::now();

    auto sol = find_quintuplet(UPPER_BOUND);

    numtype result = 0;
    for (const auto& p : sol)
        result += p;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The solution is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}