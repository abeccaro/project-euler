//
// Created by Alex Beccaro on 15/01/2020.
//

#include "problem144.hpp"
#include "cmath"

using std::abs;

namespace problems {

    problem144::point::point(): point(0, 0) {}

    problem144::point::point(double x, double y): x(x), y(y) {}

    bool problem144::point::operator==(const point &other) const {
        return abs(x - other.x) < epsilon && abs(y - other.y) < epsilon;
    }

    bool problem144::point::operator!=(const point &other) const {
        return abs(x - other.x) > epsilon || abs(y - other.y) > epsilon;
    }


    uint32_t problem144::solve() {
        point old(0, 10.1);
        point start(1.4, -9.6);
        uint32_t collisions = 1;

        for (; start.y < 0 || abs(start.x) > 0.01; collisions++) {
            double tangent_m = -4 * start.x / start.y;
            double normal_m = -1 / tangent_m;
            double normal_q = start.y - normal_m * start.x;

            double m2 = normal_m * normal_m;
            point refl;
            refl.x = ((1 - m2) * old.x + 2 * normal_m * (old.y - normal_q)) / (m2 + 1);
            refl.y = ((m2 - 1) * old.y + 2 * normal_m * old.x + 2 * normal_q) / (m2 + 1);

            double m = (refl.y - start.y) / (refl.x - start.x);
            double q = start.y - m * start.x;

            point collision;
            m2 = m * m;
            double q2 = q * q;
            collision.x = -(2 * m * q + sqrt(4 * m2 * q2 - 4 * (4 + m2) * (q2 - 100))) / (8 + 2 * m2);
            collision.y = m * collision.x + q;

            if (collision == start) {
                collision.x = -(2 * m * q - sqrt(4 * m2 * q2 - 4 * (4 + m2) * (q2 - 100))) / (8 + 2 * m2);
                collision.y = m * collision.x + q;
            }

            old = start;
            start = collision;
        }

        return collisions - 1;
    }

}