//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem11.hpp"
#include <input.hpp>

using std::vector;
using input::read_matrix;
using input::problems_folder;

namespace problems {
    uint32_t problem11::solve(uint32_t size) {
        vector<vector<uint32_t>> matrix = read_matrix<uint32_t>(problems_folder + "1-50/11/input.txt");

        uint32_t maxProd = 0;

        for (uint32_t i = 0; i < matrix.size(); i++) {
            for (uint32_t j = 0; j < matrix[i].size(); j++) {
                bool canMoveRight = j <= matrix[i].size() - size;
                bool canMoveUp = i >= size - 1;
                bool canMoveDown = i <= matrix.size() - size;

                // horizontal
                if (canMoveRight) {
                    uint32_t prod = 1;
                    for (uint32_t k = 0; k < size; k++)
                        prod *= matrix[i][j + k];
                    maxProd = std::max(prod, maxProd);
                }

                // vertical
                if (canMoveDown) {
                    uint32_t prod = 1;
                    for (uint32_t k = 0; k < size; k++)
                        prod *= matrix[i + k][j];
                    maxProd = std::max(prod, maxProd);
                }

                // diagonal bottom-right
                if (canMoveDown && canMoveRight) {
                    uint32_t prod = 1;
                    for (uint32_t k = 0; k < size; k++)
                        prod *= matrix[i + k][j + k];
                    maxProd = std::max(prod, maxProd);
                }

                // diagonal top-right
                if (canMoveUp && canMoveRight) {
                    uint32_t prod = 1;
                    for (uint32_t k = 0; k < size; k++)
                        prod *= matrix[i - k][j + k];
                    maxProd = std::max(prod, maxProd);
                }
            }
        }

        return maxProd;
    }
}