//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem11.hpp"
#include <input.hpp>

using namespace input;

using ulong = unsigned long;

namespace problems {
    uint problem11::solve(uint size) {
        std::vector<std::vector<uint>> matrix = read_matrix<uint>(problems_folder + "1-50/11/input.txt");

        ulong maxProd = 0;

        for (ulong i = 0; i < matrix.size(); i++) {
            for (ulong j = 0; j < matrix[i].size(); j++) {
                bool canMoveRight = j <= matrix[i].size() - size;
                bool canMoveUp = i >= size - 1;
                bool canMoveDown = i <= matrix.size() - size;

                // horizontal
                if (canMoveRight) {
                    ulong prod = 1;
                    for (uint k = 0; k < size; k++)
                        prod *= matrix[i][j + k];
                    maxProd = std::max(prod, maxProd);
                }

                // vertical
                if (canMoveDown) {
                    ulong prod = 1;
                    for (uint k = 0; k < size; k++)
                        prod *= matrix[i + k][j];
                    maxProd = std::max(prod, maxProd);
                }

                // diagonal bottom-right
                if (canMoveDown && canMoveRight) {
                    ulong prod = 1;
                    for (uint k = 0; k < size; k++)
                        prod *= matrix[i + k][j + k];
                    maxProd = std::max(prod, maxProd);
                }

                // diagonal top-right
                if (canMoveUp && canMoveRight) {
                    ulong prod = 1;
                    for (uint k = 0; k < size; k++)
                        prod *= matrix[i - k][j + k];
                    maxProd = std::max(prod, maxProd);
                }
            }
        }

        return maxProd;
    }
}