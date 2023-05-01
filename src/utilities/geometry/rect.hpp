//
// Created by Alex Beccaro on 30/04/2023.
//
#ifndef PROJECT_EULER_RECT_HPP
#define PROJECT_EULER_RECT_HPP

#include "fraction.hpp"
#include "point.hpp"
#include "template_conditions.hpp"

namespace geometry {
    template <class T, class = typename std::enable_if<
            template_conditions::is_any_number<T>::value ||
            std::is_convertible<T, fractions::fraction<boost::multiprecision::cpp_int>>::value>>
    class rect {
    private:
        bool vertical = false;
        T m, q;

    public:
        /**
         * Default constructor for y = 0.
         */
        rect();

        /**
         * Constructor for y = mx + q.
         */
        rect(const T& m, const T& q);

        /**
         * Constructor for vertical rect x = q.
         */
        explicit rect(const T& q);

        /**
         * Constructor for the unique rect passing through given points
         */
        rect(const point<T>& p1, const point<T>& p2);

        /**
         * Copy constructor for rect r
         */
        rect(const rect<T>& r);

        /**
         * Assignment operator
         * @param r The value to assign
         * @return The reference to this object
         */
        rect<T>& operator = (const rect<T>& r);

        /**
         * Equality check.
         * @param other The other rect
         * @return True if they are equal, false otherwise
         */
        bool operator==(const rect<T>& other) const;

        /**
         * Inequality check.
         * @param other The other rect
         * @return True if they are different, false otherwise
         */
        bool operator!=(const rect<T>& other) const;

        /**
         * Cast to another rect type
         * @return The closest representation of this rect in type rect<U>
         */
        template<class U, class = typename std::enable_if<std::is_convertible<T, U>::value>::type>
        explicit operator rect<U> () const;

        /**
         * Looks for a single intersection point between this and other rect. If rects are overlapping none is returned.
         * @param other The other rect
         * @return The single intersection point if present, empty otherwise
         */
        std::optional<point<T>> find_intersection(const rect<T>& other) const;

        /**
         * Checks if given point is contained in this rect
         * @param p The point to check
         * @return True if the point is part of the rect, false otherwise
         */
        bool contains(const point<T>& p) const;
    };

    /**
     * Output stream operator.
     * @param os The stream
     * @param r The rect
     * @return The stream with this rect representation
     */
    template<class T>
    std::ostream& operator<<(std::ostream& os, const rect<T>& r);

}

#include "rect.ipp"

#endif //PROJECT_EULER_RECT_HPP
