//
// Created by Alex Beccaro on 30/04/2023.
//
#ifndef PROJECT_EULER_POINT_HPP
#define PROJECT_EULER_POINT_HPP

#include "fraction.hpp"
#include "template_conditions.hpp"

namespace geometry {
    template <class T, class = typename std::enable_if<
            template_conditions::is_any_number<T>::value ||
            std::is_convertible<T, fractions::fraction<boost::multiprecision::cpp_int>>::value>>
    class point {
    public:
        T x, y;

        /**
         * Default constructor for origin.
         */
        point();

        /**
         * Constructor for point at (x, y).
         */
        point(const T& x, const T& y);

        /**
         * Constructor for point at (x, y) from pair.
         */
        point(const std::pair<T, T>& p);

        /**
         * Copy constructor for point p
         */
        point(const point<T>& p);

        /**
         * Assignment operator
         * @param p The value to assign
         * @return The reference to this object
         */
        point<T>& operator = (const point<T>& p);

        /**
         * Equality check.
         * @param other The other point
         * @return True if they are equal, false otherwise
         */
        bool operator==(const point<T>& other) const;

        /**
         * Inequality check.
         * @param other The other point
         * @return True if they are different, false otherwise
         */
        bool operator!=(const point<T>& other) const;

        /**
         * Cast to another point type
         * @return The closest representation of this point in type point<U>
         */
        template<class U, class = typename std::enable_if<std::is_convertible<T, U>::value>::type>
        explicit operator point<U> () const;

        /**
         * Cast to a pair of coordinates
         * @return The representation of this point as a pair of coordinates
         */
        explicit operator std::pair<T, T> () const;
    };

    /**
     * Output stream operator.
     * @param os The stream
     * @param p The point
     * @return The stream with this point representation
     */
    template<class T>
    std::ostream& operator<<(std::ostream& os, const point<T>& p);

}

#include "point.ipp"

#endif //PROJECT_EULER_POINT_HPP
