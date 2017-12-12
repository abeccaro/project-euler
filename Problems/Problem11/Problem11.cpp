//
// Created by Alex Beccaro on 12/12/17.
//

#include <iostream>
#include "../../Utilities/InputUtilities.h"

using namespace std;
using namespace chrono;
using namespace input_utilities;

/**
 * Calculates max product of 'size' adjacent numbers in given vector.
 * @param matrix The matrix
 * @param size The number of terms in the products
 * @return The maximum product
 */
long maxAdjacentProduct(const vector<vector<int>>& matrix, const int size) {
    long maxProd = numeric_limits<long>::min();

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            bool canMoveRight = j <= matrix[i].size() - size;
            bool canMoveUp = i >= size - 1;
            bool canMoveDown = i <= matrix.size() - size;

            // horizontal
            if (canMoveRight) {
                long prod = 1;
                for (int k = 0; k < size; k++)
                    prod *= matrix[i][j + k];
                maxProd = max(prod, maxProd);
            }

            // vertical
            if (canMoveDown) {
                long prod = 1;
                for (int k = 0; k < size; k++)
                    prod *= matrix[i + k][j];
                maxProd = max(prod, maxProd);
            }

            // diagonal bottom-right
            if (canMoveDown && canMoveRight) {
                long prod = 1;
                for (int k = 0; k < size; k++)
                    prod *= matrix[i + k][j + k];
                maxProd = max(prod, maxProd);
            }

            // diagonal top-right
            if (canMoveUp && canMoveRight) {
                long prod = 1;
                for (int k = 0; k < size; k++)
                    prod *= matrix[i - k][j + k];
                maxProd = max(prod, maxProd);
            }
        }
    }

    return maxProd;
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const int SIZE = 4;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    vector<vector<int>> matrix = readIntMatrix(projectPath + "Problems/Problem11/input.txt");

//    for (vector<int> row : matrix) {
//        for (int n : row)
//            cout << n << " ";
//        cout << endl;
//    }

    long product = maxAdjacentProduct(matrix, SIZE);

    double time = duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000000.0;

    cout << "The solution is " << product << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}