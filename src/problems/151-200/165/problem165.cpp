//
// Created by Alex Beccaro on 29/04/2023.
//

#include "generics.hpp"
#include "geometry/point.hpp"
#include "hash_functions.hpp"
#include "problem165.hpp"
#include "unordered_set"


using fractions::fraction;
using generics::mod_pow;
using std::unordered_set;
using std::vector;

using point = geometry::point<fraction<int64_t>>;
using segment = geometry::segment<fraction<int64_t>>;

namespace problems {
    vector<segment> problem165::generate_segments()  {
        vector<segment> segments;

        int64_t s = 290797;
        for (uint32_t i = 0; i < 5000; i++) {
            s = mod_pow(s, 2ll, 50515093ll);
            int64_t x1 = s % 500;

            s = mod_pow(s, 2ll, 50515093ll);
            int64_t y1 = s % 500;

            s = mod_pow(s, 2ll, 50515093ll);
            int64_t x2 = s % 500;

            s = mod_pow(s, 2ll, 50515093ll);
            int64_t y2 = s % 500;

            segments.push_back({{x1, y1}, {x2, y2}});
        }

        return segments;
    }

    uint64_t problem165::solve() {
        auto segments = generate_segments();
        unordered_set<point> result;

        fraction<int64_t>::auto_reduce(true);
        for (auto i = segments.begin(); i != segments.end(); i++) {
            for (auto j = i + 1; j != segments.end(); j++) {
                auto intersection = i->get_rect().find_intersection(j->get_rect());
                if (intersection.has_value() &&
                i->contains(intersection.value()) && j->contains(intersection.value()) &&
                intersection != i->p1 && intersection != i->p2 && intersection != j->p1 && intersection != j->p2)
                    result.insert(intersection.value());
            }
        }

        fraction<int64_t>::auto_reduce(false);
        return result.size();
    }
}