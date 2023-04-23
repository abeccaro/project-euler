//
// Created by Alex Beccaro on 17/12/2019.
//

#ifndef PROJECT_EULER_PROBLEM142_HPP
#define PROJECT_EULER_PROBLEM142_HPP

#include "cstdint"
#include "vector"
#include "unordered_map"

namespace problems {
    class problem142 {
    private:
        static std::tuple<uint32_t, uint32_t, uint32_t> shared_triples(
                std::unordered_map<uint32_t, std::vector<std::tuple<uint32_t, uint32_t, uint32_t>>>& triples,
                uint32_t a, uint32_t c);


    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM142_HPP
