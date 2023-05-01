//
// Created by Alex Beccaro on 30/04/2023.
//

#include "boost/functional/hash.hpp"
#include "point.hpp"

namespace geometry {

    template<class T, class V>
    point<T, V>::point() = default;

    template<class T, class V>
    point<T, V>::point(const T& x, const T& y) : x(x), y(y) {}

    template<class T, class V>
    point<T, V>::point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}

    template<class T, class V>
    point<T, V>::point(const point<T>& p) : x(p.x), y(p.y) {}

    template<class T, class V>
    point<T>& point<T, V>::operator = (const point<T>& p) {
        x = p.x;
        y = p.y;
        return *this;
    }

    template<class T, class V>
    bool point<T, V>::operator==(const point<T> &other) const {
        return x == other.x && y == other.y;
    }

    template<class T, class V>
    bool point<T, V>::operator!=(const point<T> &other) const {
        return x != other.x || y != other.y;
    }

    template<class T, class V>
    template<class U, class>
    point<T, V>::operator point<U> () const {
        return point<U>(this);
    }

    template<class T, class V>
    point<T, V>::operator std::pair<T, T> () const {
        return std::make_pair(x, y);
    }

    template<class T>
    std::ostream& operator<<(std::ostream& os, const point<T>& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    template<class T>
    std::size_t hash_value(point<T> const& p) {
        size_t seed = 0;
        boost::hash_combine(seed, p.x);
        boost::hash_combine(seed, p.y);
        return seed;
    }

}

namespace std {
    template<class T>
    struct hash<geometry::point<T>> {
        auto operator()(const geometry::point<T> &p) const -> size_t {
            size_t seed = 0;
            boost::hash_combine(seed, p.x);
            boost::hash_combine(seed, p.y);
            return seed;
        }
    };
}