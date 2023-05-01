//
// Created by Alex Beccaro on 30/04/2023.
//

#include "segment.hpp"

namespace geometry {

    template<class T, class V>
    segment<T, V>::segment() = default;

    template<class T, class V>
    segment<T, V>::segment(const point<T>& p1, const point<T>& p2) : p1(p1), p2(p2) {}

    template<class T, class V>
    segment<T, V>::segment(const std::pair<point<T>, point<T>>& p) : p1(p.first), p2(p.second) {}

    template<class T, class V>
    segment<T, V>::segment(const segment<T>& s) : p1(s.p1), p2(s.p2) {}

    template<class T, class V>
    segment<T>& segment<T, V>::operator = (const segment<T>& s) {
        p1 = s.p1;
        p2 = s.p2;
        return *this;
    }

    template<class T, class V>
    bool segment<T, V>::operator==(const segment<T>& other) const {
        return (p1 == other.p1 && p2 == other.p2) || (p1 == other.p2 && p2 == other.p1);
    }

    template<class T, class V>
    bool segment<T, V>::operator!=(const segment<T>& other) const {
        return !((p1 == other.p1 && p2 == other.p2) || (p1 == other.p2 && p2 == other.p1));
    }

    template<class T, class V>
    template<class U, class>
    segment<T, V>::operator segment<U> () const {
        return segment<U>(this);
    }

    template<class T, class V>
    segment<T, V>::operator std::pair<point<T>, point<T>> () const {
        return std::make_pair(p1, p2);
    }

    template<class T>
    std::ostream& operator<<(std::ostream& os, const segment<T>& s) {
        os << s.p1 << " - " << s.p2;
        return os;
    }

    template<class T, class V>
    rect<T> segment<T, V>::get_rect() {
        if (!r.has_value())
            r = rect(p1, p2);
        return r.value();
    }

    template<class T, class V>
    bool segment<T, V>::contains(const point<T> &p) {
        return p.x >= std::min(p1.x, p2.x) && p.x <= std::max(p1.x, p2.x) &&
                p.y >= std::min(p1.y, p2.y) && p.y <= std::max(p1.y, p2.y) &&
                get_rect().contains(p);
    }
}