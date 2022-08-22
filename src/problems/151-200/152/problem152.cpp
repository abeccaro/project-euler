//
// Created by Alex Beccaro on 17/08/2022.
//

#include "problem152.hpp"
#include "fraction.hpp"
#include "generics.hpp"
#include <vector>

using std::vector;
using std::map;
using std::set;
using fractions::fraction;
using std::find;
using std::sort;
using std::adjacent_find;
using generics::combinations;

namespace problems {
    problem152::group::group() = default;

    problem152::group::group(const fraction<uint64_t>& f) : fractions({f}), sum(f) {}

    problem152::group::group(const vector<group>& groups) : fractions(), sum(0) {
        for (const auto& group : groups) {
            fractions.insert(fractions.begin(), group.fractions.begin(), group.fractions.end());
            sum += group.sum;
        }
        sort(fractions.begin(), fractions.end());
        sum.reduce();
    }

    bool problem152::group::is_valid() const {
        return std::adjacent_find(fractions.begin(), fractions.end()) == fractions.end();
    }

    bool problem152::group::operator == (const group& g2) const {
        return fractions == g2.fractions;
    }

    bool problem152::group::operator < (const group& g2) const {
        return fractions < g2.fractions;
    }


    vector<problem152::group> problem152::from_prime_factors(const vector<uint64_t>& factors, uint64_t ub) {
        vector<uint64_t> nums = {1};
        map<uint64_t, uint64_t> indices;

        for (const uint64_t factor : factors)
            indices.insert({factor, 0});

        std::pair<uint64_t, uint64_t> next = *indices.begin();
        while(next.first * nums[next.second] <= ub) {
            nums.push_back(next.first * nums[next.second]);
            indices[next.first]++;
            next = *std::min_element(indices.begin(), indices.end(), [nums](const auto& pair1, const auto& pair2) {
                return pair1.first * nums[pair1.second] < pair2.first * nums[pair2.second];
            });
        }

        nums.erase(nums.begin());
        vector<group> result;
        std::transform(nums.begin(),  nums.end(), std::back_inserter(result), [](uint64_t n){ return group(fraction<uint64_t>(1, n*n)); });
        return result;
    }

    map<fraction<uint64_t>, vector<problem152::group>> problem152::group_by_sum(const vector<group>& groups) {
        map<fraction<uint64_t>, vector<group>> result;
        for (uint64_t k = 0; k <= groups.size(); k++) {
            vector<vector<group>> combs = combinations(groups, k);
            for (const auto& comb : combs) {
                group new_group(comb);
                if (result.find(new_group.sum) == result.end())
                    result.insert({new_group.sum, {new_group}});
                else
                    result[new_group.sum].push_back(new_group);
            }
        }
        return result;
    }

    uint32_t problem152::solve(uint32_t ub) {
        fraction<uint64_t> one_half(1, 2);

        set<group> candidates; // groups of fractions that could produce the required sum
        vector<uint64_t> too_slow; // primes for which the preliminary analysis would be too slow. All multiples are considered good
        vector<uint64_t> to_remove; // primes for which no multiple group can produce required sum
        vector<uint64_t> ps = primes::primes_up_to<uint64_t>(ub);
        for (uint64_t p : ps) {
            vector<group> prime_multiples; // all multiples of prime p up to the upper bound
            for (uint64_t i = p; i <= ub; i += p)
                prime_multiples.emplace_back(fraction<uint64_t>(1, i*i));

            if (prime_multiples.size() > 20) { // too slow, arbitrary number based on computer efficiency
                too_slow.push_back(p);
                continue;
            }

            // calculate groups to add
            vector<group> to_add;
            for (uint64_t k = 2; k < prime_multiples.size(); k++) {
                vector<vector<group>> combs = combinations(prime_multiples, k);
                for (const auto& comb : combs) {
                    group g(comb);
                    if (g.sum.denominator() % p != 0) {
                        to_add.emplace_back(g);
                    }
                }
            }

            // if no group is added then p and all multiples are set to be removed
            if (to_add.empty())
                to_remove.push_back(p);
            else {
                // if there are less groups than p multiples keep the groups only (heuristic)
                if (to_add.size() < prime_multiples.size()) {
                    candidates.insert(to_add.begin(),  to_add.end());
                    to_remove.push_back(p);
                }
                else {
                    // add to candidates each fraction inside the to_add groups
                    for (const auto& g : to_add) {
                        for (const auto& f : g.fractions)
                            candidates.insert(group(f));
                    }
                }
            }
        }

        // add candidates from primes too slow to filter
        auto additional = from_prime_factors(too_slow, ub);
        candidates.insert(additional.begin(),  additional.end());

        // remove all multiples of primes in to_remove
        for (auto i = candidates.begin(); i != candidates.end(); i++) {
            for (const auto& p : to_remove) {
                if ((*i).sum.denominator() % p == 0) {
                    candidates.erase(i--);
                    break;
                }
            }
        }

        // separate candidates in 2 groups of equal size
        vector<group> g1, g2;
        for (auto i = candidates.begin(); i != candidates.end(); i++) {
            if (std::distance(candidates.begin(), i) < candidates.size() / 2)
                g1.emplace_back(*i);
            else
                g2.emplace_back(*i);
        }

        // group each group of fractions by their sum
        map<fraction<uint64_t>, vector<group>> m1 = group_by_sum(g1);
        map<fraction<uint64_t>, vector<group>> m2 = group_by_sum(g2);

        // Two sum problem: search and count complementary sums for 1/2 and check group combinations validity.
        uint32_t result = 0;
        auto i1 = m1.rbegin();
        auto i2 = m2.begin();
        while (i1 != m1.rend() && i2 != m2.end()) {
            auto sum = i1->first + i2->first;

            if (sum == one_half) {
                for (const auto& group1 : i1->second) {
                    for (const auto& group2 : i2->second) {
                        group g({group1, group2});
                        if (g.is_valid())
                            result++;
                    }
                }
            }

            if (sum > one_half)
                i1++;
            else
                i2++;
        }

        return result;
    }
}