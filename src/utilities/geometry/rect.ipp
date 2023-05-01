//
// Created by Alex Beccaro on 30/04/2023.
//

#include "boost/functional/hash.hpp"
#include "rect.hpp"

namespace geometry {

    template<class T, class V>
    rect<T, V>::rect() = default;

    template<class T, class V>
    rect<T, V>::rect(const T& m, const T& q) : m(m), q(q) {}

    template<class T, class V>
    rect<T, V>::rect(const T& q) : vertical(true), q(q) {}

    template<class T, class V>
    rect<T, V>::rect(const point<T>& p1, const point<T>& p2) {
        if (p1.x == p2.x) {
            vertical = true;
            q = p1.x;
        }
        else {
            m = (p2.y - p1.y) / (p2.x - p1.x);
            q = p1.y - m * p1.x;
        }
    }

    template<class T, class V>
    rect<T, V>::rect(const rect<T>& r) : vertical(r.vertical), m(r.m), q(r.q) {}

    template<class T, class V>
    rect<T>& rect<T, V>::operator = (const rect<T>& r) {
        vertical = r.vertical;
        m = r.m;
        q = r.q;
        return *this;
    }

    template<class T, class V>
    bool rect<T, V>::operator==(const rect<T> &other) const {
        return vertical == other.vertical && m == other.m && q == other.q;
    }

    template<class T, class V>
    bool rect<T, V>::operator!=(const rect<T> &other) const {
        return vertical != other.vertical || m != other.m || q != other.q;
    }

    template<class T, class V>
    template<class U, class>
    rect<T, V>::operator rect<U> () const {
        return rect<U>(this);
    }

    template<class T>
    std::ostream& operator<<(std::ostream& os, const rect<T>& r) {
        if (r.vertical)
            os << "x = " << r.q;
        else {
            os << "y = ";
            if (r.m == 0)
                os << r.q;
            else {
                os << r.m << " * x";
                if (r.q != 0)
                    os << r.q > 0 ? " + " : " " << r.q;
            }
        }
        return os;
    }

    template<class T, class V>
    std::optional<point<T>> rect<T, V>::find_intersection(const rect<T>& other) const {
        if (vertical) {
            if (other.vertical)
                return {};
            T y = other.m * q + other.q;
            return point(q, y);
        }

        if (other.vertical) {
            T y = m * other.q + q;
            return point(other.q, y);
        }

        if (m == other.m)
            return {};

        T x = (other.q - q) / (m - other.m);
        T y = m * x + q;
        return point(x, y);
    }

    template<class T, class V>
    bool rect<T, V>::contains(const point<T> &p) const {
        if (vertical)
            return p.x == q;
        return p.y == m * p.x + q;
    }

}

namespace std {
    template<class T>
    struct hash<geometry::rect<T>> {
        auto operator()(const geometry::rect<T> &r) const -> size_t {
            size_t seed = 0;
            boost::hash_combine(seed, r.m);
            boost::hash_combine(seed, r.q);
            boost::hash_combine(seed, r.vertical);
            return seed;
        }
    };
}