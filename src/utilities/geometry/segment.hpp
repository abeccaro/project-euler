//
// Created by Alex Beccaro on 30/04/2023.
//
#ifndef PROJECT_EULER_SEGMENT_HPP
#define PROJECT_EULER_SEGMENT_HPP

#include "fraction.hpp"
#include "point.hpp"
#include "rect.hpp"
#include "template_conditions.hpp"

namespace geometry {
    template <class T, class = typename std::enable_if<
            template_conditions::is_any_number<T>::value ||
            std::is_convertible<T, fractions::fraction<boost::multiprecision::cpp_int>>::value>>
    class segment {
    private:
        std::optional<rect<T>> r;

    public:
        point<T> p1, p2;

        /**
         * Default constructor for degenerate segment on origin.
         */
        segment();

        /**
         * Constructor for segment from p1 to p2
         */
        segment(const point<T>& p1, const point<T>& p2);

        /**
         * Constructor for segment from p1 to p2 from pair.
         */
        segment(const std::pair<point<T>, point<T>>& p);

        /**
         * Copy constructor for segment s
         */
        segment(const segment<T>& s);

        /**
         * Assignment operator
         * @param p The value to assign
         * @return The reference to this object
         */
        segment<T>& operator = (const segment<T>& p);

        /**
         * Equality check.
         * @param other The other segment
         * @return True if they are equal, false otherwise
         */
        bool operator==(const segment<T>& other) const;

        /**
         * Inequality check.
         * @param other The other segment
         * @return True if they are different, false otherwise
         */
        bool operator!=(const segment<T>& other) const;

        /**
         * Cast to another segment type
         * @return The closest representation of this segment in type segment<U>
         */
        template<class U, class = typename std::enable_if<std::is_convertible<T, U>::value>::type>
        explicit operator segment<U> () const;

        /**
         * Cast to a pair of points
         * @return The representation of this segment as a pair of point<T>
         */
        explicit operator std::pair<point<T>, point<T>> () const;

        /**
         * Calculates if necessary and returns the rect containing this segment
         * @return The rect containing this segment
         */
        geometry::rect<T> get_rect();

        /**
         * Checks if given point is contained in this segment
         * @param p The point to check
         * @return True if the point is part of the segment, false otherwise
         */
        bool contains(const point<T>& p);
    };

    /**
     * Output stream operator.
     * @param os The stream
     * @param s The segment
     * @return The stream with this segment representation
     */
    template<class T>
    std::ostream& operator<<(std::ostream& os, const segment<T>& s);

}

#include "segment.ipp"

#endif //PROJECT_EULER_SEGMENT_HPP
