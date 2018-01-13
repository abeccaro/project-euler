//
// Created by Alex Beccaro on 11/01/18.
//

#include <iostream>
#include <map>
#include <series/figurate_number.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using series::figurate_number;

using numtype = unsigned int;
using num_pair = pair<numtype, numtype>; // (number of sides of figure, figurate number)

/**
 * Search for a cycle of length = 'length' in given map starting from given solution and testing entry as next element.
 * @param m The map with data
 * @param entry The next element entry to test
 * @param sol The partial solution found. Final solution will be stored here.
 * @param length The length of desired solution
 * @return
 */
bool find_cycle(const map<num_pair, vector<num_pair>>& m,
         const pair<num_pair, vector<num_pair>>& entry,
         vector<num_pair>& sol, const numtype& length) {
    numtype n = entry.first.first; // number of sides of figure

    if (count_if(sol.begin(), sol.end(), [n](num_pair p){return p.first == n;}) > 0)
        return false;

    sol.emplace_back(n, entry.first.second);
    if (sol.size() == length) {
        if (sol.front().second / 100 == sol.back().second % 100)
            return true;
        else {
            sol.pop_back();
            return false;
        }
    }

    for (const auto& key : entry.second) {
        pair<num_pair, vector<num_pair>> sub_entry = *m.find(key);
        if (find_cycle(m, sub_entry, sol, length))
            return true;
    }

    sol.pop_back();
    return false;
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype CYCLE_LENGTH = 6;

    timer::time_point start = timer::now();

    map<num_pair, vector<num_pair>> m; // number -> list of numbers that can follow key in a cycle

    for (numtype i = 3; i < 3 + CYCLE_LENGTH; i++) {
        // generate figurate numbers with 4 digits
        figurate_number<numtype> s(i);
        vector<numtype> numbers = s.get_while([](numtype n){return n < 10000;}, [](numtype n){return n >= 1000;});

        // for each number generated update already present entries and create new one
        for (const auto& n : numbers) {
            num_pair c(i, n);
            vector<num_pair> v;

            // for each entry already in the map with different sides count
            for (auto& entry : m)
                if (entry.first.first != i) {
                    // if cyclic continuation of already present entry then add to its list
                    if (entry.first.second % 100 == n / 100)
                        entry.second.push_back(c);

                    // if entry starting number is cyclic continuation of n then add it to its list
                    if (entry.first.second / 100 == n % 100)
                        v.push_back(entry.first);
                }

            // add new entry
            m[c] = v;
        }
    }

    numtype result = 0;
    // for each entry test if a cycle of N is found starting from that entry
    for (const auto& entry : m) {
        vector<num_pair> solution;
        if (find_cycle(m, entry, solution, CYCLE_LENGTH)) {
            for (const auto& p : solution)
                result += p.second;
            break;
        }
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of the only set of six cyclic 4-digit numbers for which each polygonal type is represented by a "
         << "different number in the set is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}