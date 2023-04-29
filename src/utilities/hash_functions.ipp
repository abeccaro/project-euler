//
// Created by Alex Beccaro on 29/04/2023.
//


#include "hash_functions.hpp"

namespace problems {
    template<class T1, class T2>
    size_t pair_hash<T1, T2>::operator()(const std::pair<T1, T2>& t) const {
        return boost::hash_value(t);
    }
}