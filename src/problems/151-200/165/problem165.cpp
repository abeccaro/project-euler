//
// Created by Alex Beccaro on 29/04/2023.
//

#include "fraction.hpp"
#include "geometry/point.hpp"
#include "problem165.hpp"
#include "unordered_set"


using fractions::fraction;
using std::unordered_set;
using std::vector;

using point = geometry::point<fraction<int32_t>>;
using segment = geometry::segment<int32_t>;

namespace problems {
    vector<segment> problem165::generate_segments()  {
        vector<segment> segments;

        int64_t s = 290797;
        for (uint32_t i = 0; i < 5000; i++) {
            s = s * s % 50515093;
            int32_t x1 = s % 500;

            s = s * s % 50515093;
            int32_t y1 = s % 500;

            s = s * s % 50515093;
            int32_t x2 = s % 500;

            s = s * s % 50515093;
            int32_t y2 = s % 500;

            segments.push_back({{x1, y1}, {x2, y2}});
        }

        return segments;
    }

    uint64_t problem165::solve() {
        auto segments = generate_segments();
        unordered_set<point> result;

        // for each pair use algorithm explained here https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection
        // c# are coefficients stored for efficiency
        for (auto i = segments.begin(); i != segments.end(); i++) {
            int32_t c1 = i->p1.x - i->p2.x;
            int32_t c3 = i->p1.y - i->p2.y;
            int32_t c7 = i->p1.x * i->p2.y - i->p1.y * i->p2.x;
            for (auto j = i + 1; j != segments.end(); j++) {
                int32_t c2 = j->p1.y - j->p2.y;
                int32_t c4 = j->p1.x - j->p2.x;
                int32_t den = c1 * c2 - c3 * c4;
                if (den == 0) // collinear
                    continue;

                int32_t c5 = i->p1.x - j->p1.x;
                int32_t c6 = i->p1.y - j->p1.y;
                fraction<int32_t> t(c5 * c2 - c6 * c4, den);
                if (!(t > 0 && t < 1)) // outside first segment
                    continue;
                fraction<int32_t> u(c5 * c3 - c6 * c1, den);
                if (!(u > 0 && u < 1)) // outside second segment
                    continue;

                int32_t c8 = j->p1.x * j->p2.y - j->p1.y * j->p2.x;
                fraction<int32_t> x(c7 * c4 - c8 * c1, den);
                fraction<int32_t> y(c7 * c2 - c8 * c3, den);
                x.reduce();
                y.reduce();
                point intersection(x, y);

                result.insert(intersection);
            }
        }

        return result.size();
    }
}