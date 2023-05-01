//
// Created by Alex Beccaro on 30/04/2023.
//

#include "boost/functional/hash.hpp"
#include "line.hpp"

namespace geometry {

    template<class T, class V>
    line<T, V>::line() = default;

    template<class T, class V>
    line<T, V>::line(const T& m, const T& q) : m(m), q(q) {}

    template<class T, class V>
    line<T, V>::line(const T& q) : vertical(true), q(q) {}

    template<class T, class V>
    line<T, V>::line(const point<T>& p1, const point<T>& p2) {
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
    line<T, V>::line(const line<T>& l) : vertical(l.vertical), m(l.m), q(l.q) {}

    template<class T, class V>
    line<T>& line<T, V>::operator = (const line<T>& l) {
        vertical = l.vertical;
        m = l.m;
        q = l.q;
        return *this;
    }

    template<class T, class V>
    bool line<T, V>::operator==(const line<T> &other) const {
        return vertical == other.vertical && m == other.m && q == other.q;
    }

    template<class T, class V>
    bool line<T, V>::operator!=(const line<T> &other) const {
        return vertical != other.vertical || m != other.m || q != other.q;
    }

    template<class T, class V>
    template<class U, class>
    line<T, V>::operator line<U> () const {
        return line<U>(this);
    }

    template<class T>
    std::ostream& operator<<(std::ostream& os, const line<T>& l) {
        if (l.vertical)
            os << "x = " << l.q;
        else {
            os << "y = ";
            if (l.m == 0)
                os << l.q;
            else {
                os << l.m << " * x";
                if (l.q != 0)
                    os << l.q > 0 ? " + " : " " << l.q;
            }
        }
        return os;
    }

    template<class T, class V>
    bool line<T, V>::contains(const point<T> &p) const {
        if (vertical)
            return p.x == q;
        return p.y == m * p.x + q;
    }

}

namespace std {
    template<class T>
    struct hash<geometry::line<T>> {
        auto operator()(const geometry::line<T> &r) const -> size_t {
            size_t seed = 0;
            boost::hash_combine(seed, r.m);
            boost::hash_combine(seed, r.q);
            boost::hash_combine(seed, r.vertical);
            return seed;
        }
    };
}