//
// Created by Alex Beccaro on 20/12/17.
//
#ifndef PROJECT_EULER_TEMPLATE_CONDITIONS_H
#define PROJECT_EULER_TEMPLATE_CONDITIONS_H

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

namespace template_conditions {

    template<typename T>
    struct is_any_integral : public std::integral_constant<bool,
            std::is_integral<T>::value ||
            std::is_convertible<T, boost::multiprecision::cpp_int>::value> {};

    template<typename T>
    struct is_any_number : public std::integral_constant<bool,
            is_any_integral<T>::value ||
            std::is_convertible<T, boost::multiprecision::number<boost::multiprecision::cpp_dec_float<
                    std::numeric_limits<unsigned int>::max()>>>::value> {};

}

#endif //PROJECT_EULER_TEMPLATE_CONDITIONS_H
