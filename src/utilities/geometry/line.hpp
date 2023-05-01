//
// Created by Alex Beccaro on 30/04/2023.
//
#ifndef PROJECT_EULER_LINE_HPP
#define PROJECT_EULER_LINE_HPP

#include "fraction.hpp"
#include "point.hpp"
#include "template_conditions.hpp"

namespace geometry {
    template <class T, class = typename std::enable_if<
            template_conditions::is_any_number<T>::value ||
            std::is_convertible<T, fractions::fraction<boost::multiprecision::cpp_int>>::value>>
    class line {
    private:
        bool vertical = false;
        T m, q;

    public:
        /**
         * Default constructor for y = 0.
         */
        line();

        /**
         * Constructor for y = mx + q.
         */
        line(const T& m, const T& q);

        /**
         * Constructor for vertical line x = q.
         */
        explicit line(const T& q);

        /**
         * Constructor for the unique line passing through given points
         */
        line(const point<T>& p1, const point<T>& p2);

        /**
         * Copy constructor for line l
         */
        line(const line<T>& l);

        /**
         * Assignment operator
         * @param l The value to assign
         * @return The reference to this object
         */
        line<T>& operator = (const line<T>& l);

        /**
         * Equality check.
         * @param other The other line
         * @return True if they are equal, false otherwise
         */
        bool operator==(const line<T>& other) const;

        /**
         * Inequality check.
         * @param other The other line
         * @return True if they are different, false otherwise
         */
        bool operator!=(const line<T>& other) const;

        /**
         * Cast to another line type
         * @return The closest representation of this line in type line<U>
         */
        template<class U, class = typename std::enable_if<std::is_convertible<T, U>::value>::type>
        explicit operator line<U> () const;

        /**
         * Checks if given point is contained in this line
         * @param p The point to check
         * @return True if the point is part of the line, false otherwise
         */
        bool contains(const point<T>& p) const;
    };

    /**
     * Output stream operator.
     * @param os The stream
     * @param l The line
     * @return The stream with this line representation
     */
    template<class T>
    std::ostream& operator<<(std::ostream& os, const line<T>& l);

}

#include "line.ipp"

#endif //PROJECT_EULER_LINE_HPP
