//
// Created by Alex Beccaro on 20/12/17.
//
#ifndef PROJECT_EULER_TEMPLATE_CONDITIONS_H
#define PROJECT_EULER_TEMPLATE_CONDITIONS_H

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace boost::multiprecision;

namespace template_conditions {

    template<class T>
    struct is_any_integral : public integral_constant<bool,
            is_integral<T>::value ||
            is_convertible<T, cpp_int>::value> {};

    template<class T>
    struct is_any_number : public integral_constant<bool,
            is_any_integral<T>::value ||
            is_convertible<T, number<cpp_dec_float<numeric_limits<unsigned int>::max()>>>::value> {};

}

#endif //PROJECT_EULER_TEMPLATE_CONDITIONS_H
