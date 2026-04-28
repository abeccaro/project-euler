//
// Created by Alex Beccaro on 26/04/2026.
//

#include "problem177.hpp"
#include "algorithm"
#include "cmath"
#include "set"
#include "unordered_map"
#include "vector"

using std::nearbyint;
using std::pair;
using std::reverse;
using std::rotate;
using std::set;
using std::unordered_map;
using std::vector;

namespace problems {
    const double DEG_TO_RAD = std::numbers::pi / 180;
    const double EPSILON = 1e-9;

    uint32_t problem177::solve() {
        // Precalculate sin and cos of integer angles
        unordered_map<int32_t, double> sins;
        unordered_map<int32_t, double> coss;
        for (int32_t n = 1; n < 179; n++) {
            sins[n] = sin(n * DEG_TO_RAD);
            coss[n] = cos(n * DEG_TO_RAD);
        }

        uint32_t result = 0;
        set<vector<int32_t>> found;
        // Fix some angles and find the other forced ones
        // Also calculate the length of the semi-diagonals assuming AO to be 1
        for (int32_t aob = 1; aob <= 90; aob++) {
            int32_t boc = 180 - aob;
            for (int32_t bac = 1; bac < 180 - aob; bac++) {
                int32_t abd = 180 - aob - bac;
                double bo = sins[bac] / sins[abd];
                // Can be changed to cbd <= (180 - theta) / 2, as suggested by philiplu, but why?
                // Reduces time by around 40%
                for (int32_t cbd = 1; cbd < 180 - boc; cbd++) {
                    int32_t acb = 180 - boc - cbd;
                    double co = bo * sins[cbd] / sins[acb];
                    for (int32_t acd = bac; acd < 180 - aob; acd++) {
                        int32_t bdc = 180 - aob - acd;
                        double od = co * sins[acd] / sins[bdc];
                        // The last two angles are forced because we know two sides and the angle between them.
                        // We just need to check that one angle is integer, and we know the last one is integer as well
                        double ad = sqrt(od * od + 1 - 2 * od * coss[boc]);
                        double adb_double = asin(sins[boc] / ad) / DEG_TO_RAD;
                        if (fabs(adb_double - nearbyint(adb_double)) > EPSILON) {
                            continue;
                        }
                        auto adb = (int32_t) nearbyint(adb_double);
                        int32_t cad = 180 - boc - adb;
                        vector<int32_t> quadrilateral({bac, abd, cbd, acb, acd, bdc, adb, cad});
                        // Check if the quadrilateral is similar to one we already count
                        if (!found.contains(quadrilateral)) {
                            // If not we count it and add its rotations and symmetries to the solutions found
                            result++;

                            found.insert(quadrilateral);
                            rotate(quadrilateral.begin(), quadrilateral.begin() + 2, quadrilateral.end());
                            found.insert(quadrilateral);
                            rotate(quadrilateral.begin(), quadrilateral.begin() + 2, quadrilateral.end());
                            found.insert(quadrilateral);
                            rotate(quadrilateral.begin(), quadrilateral.begin() + 2, quadrilateral.end());
                            found.insert(quadrilateral);
                            reverse(quadrilateral.begin(), quadrilateral.end());
                            found.insert(quadrilateral);
                            rotate(quadrilateral.begin(), quadrilateral.begin() + 2, quadrilateral.end());
                            found.insert(quadrilateral);
                            rotate(quadrilateral.begin(), quadrilateral.begin() + 2, quadrilateral.end());
                            found.insert(quadrilateral);
                            rotate(quadrilateral.begin(), quadrilateral.begin() + 2, quadrilateral.end());
                            found.insert(quadrilateral);
                        }
                    }
                }
            }
        }

        return result;
    }
}