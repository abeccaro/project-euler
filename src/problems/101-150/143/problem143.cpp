//
// Created by Alex Beccaro on 17/12/2019.
//

#define _USE_MATH_DEFINES

#include "problem143.hpp"
#include "cmath"
#include "unordered_set"
#include "numeric"
#include "generics.hpp"

using std::vector;
using std::unordered_set;
using std::unordered_map;
using generics::gcd;

using pair = std::pair<uint64_t, uint64_t>;

namespace problems {
    uint64_t problem143::solve(uint64_t ub) {
        unordered_set<uint64_t> sums;

        // generate pairs (p, q) of integer triangle sides forming a 120° angle between sides p and q
        unordered_map<uint64_t, vector<pair>> map;
        uint64_t m_ub = static_cast<uint64_t>(ceil(sqrt(ub)));
        for (uint64_t m = 2; m < m_ub; m++) {
            for (uint64_t n = 1; n < m && m + n < ub; n++) {
                // prevent duplicates
                if (m % 3 == n)
                    continue;

                uint64_t p = 2 * m * n + n*n;
                uint64_t q = m*m - n*n;

                // skip if not primitive
                if (gcd(p, q) != 1)
                    continue;

                // add to map all multiples of primitive couple
                for (uint64_t kp = p, kq = q; kp + kq < ub; kp += p, kq += q) {
                    pair to_insert;
                    if (kp > kq)
                        to_insert = {kp, kq};
                    else
                        to_insert = {kq, kp};

                    auto iter = map.find(to_insert.first);
                    if (iter != map.end())
                        iter->second.push_back(to_insert);
                    else
                        map.insert({to_insert.first, {to_insert}});
                }
            }
        }

        // Looking for solution pairs, so like (p, q) (q, r) (p, r)
        for (auto it_pq = map.begin(); it_pq != map.end(); it_pq++) {
            // skip if impossible (required at least 2 pairs starting with p)
            if (it_pq->second.size() == 1)
                continue;

            for (const pair pq : it_pq->second) {
                uint64_t p = pq.first;
                uint64_t q = pq.second;

                // look for (q, r)
                auto it_qr = map.find(q);
                if (it_qr == map.end())
                    continue;

                for (const pair qr : it_qr->second) {
                    uint64_t r = qr.second;

                    if (p + q + r > ub)
                        continue;

                    // look for (p, r)
                    for (const pair pr : it_pq->second)
                        if (pr.second == r)
                            sums.insert(p + q + r);
                }
            }
        }

        return std::accumulate(sums.begin(), sums.end(), 0ULL);
    }

}