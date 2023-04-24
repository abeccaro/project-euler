//
// Created by Alex Beccaro on 23/04/2023.
//

#ifndef PROJECT_EULER_PROBLEM161_HPP
#define PROJECT_EULER_PROBLEM161_HPP


#include "cstdint"
#include "optional"
#include "unordered_map"
#include "vector"

namespace problems {
    class problem161 {
    private:
        /**
         * Class that represents a grid state
         */
        class grid_state {
        private:
            /**
             * Index of the first empty cell
             */
            uint32_t first_empty;

            /**
             * Size of each row
             */
            uint32_t row_size;

            std::optional<grid_state> add_piece(uint32_t offset1, uint32_t offset2) const;

        public:
            /**
             * Grid in linear representation row by row
             */
            std::vector<bool> bitmask;

            grid_state(uint32_t rows, uint32_t cols);
            grid_state(const grid_state& g);

            /**
             * Tries to add all pieces at the first empty cell. Returns the vector of all valid grid states obtained this way.
             * @return the vector of all valid grid states obtained adding a piece in the first empty cell
             */
            std::vector<grid_state> add_pieces() const;
        };

        static std::unordered_map<std::vector<bool>, uint64_t> mem;

        static uint64_t count(const grid_state& g);

    public:
        /**
         * Calculates in how many ways can a n by m grid be tiled using triominoes
         * @param n the number of rows of the grid
         * @param m the number of columns of the grid
         * @return The number of ways to tile the grid
         */
        static uint64_t solve(uint64_t n = 9, uint64_t m = 12);
    };
}


#endif //PROJECT_EULER_PROBLEM161_HPP
