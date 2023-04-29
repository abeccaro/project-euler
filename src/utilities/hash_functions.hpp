//
// Created by Alex Beccaro on 29/04/2023.
//

#ifndef PROJECT_EULER_HASH_FUNCTIONS_HPP
#define PROJECT_EULER_HASH_FUNCTIONS_HPP


#include "boost/functional/hash.hpp"
#include "template_conditions.hpp"

namespace problems {
    template<class T1, class T2>
    struct pair_hash {
        size_t operator()(std::pair<T1, T2> const &t) const;
    };
}

#include "hash_functions.ipp"

#endif //PROJECT_EULER_HASH_FUNCTIONS_HPP