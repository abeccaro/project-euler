//
// Created by Alex Beccaro on 12/03/18.
//

#include "problem96.hpp"
#include <input.hpp>

using std::vector;

using input::read_matrix;
using input::problems_folder;

namespace problems {
    problem96::sudoku::sudoku(uint32_t size) : size(size), box_size((uint32_t) sqrt(size)) {
        m = vector<vector<uint32_t>>(size);
        for (auto& row : m)
            row = vector<uint32_t>(size);
    }

    problem96::sudoku::sudoku(const vector<uint32_t>& v) : size((uint32_t) sqrt(v.size())), box_size((uint32_t) sqrt(size)) {
        m = vector<vector<uint32_t>>(size);
        for (auto& row : m)
            row = vector<uint32_t>(size);

        for (uint32_t i = 0; i < size; i++)
            for (uint32_t j = 0; j < size; j++)
                m[i][j] = v[i * size + j];
    }

    bool problem96::sudoku::is_valid_value(uint32_t row, uint32_t col) {
        // std::cout << "Valid value " << row << ", " << col << std::endl;
        // row constraint
        for (uint32_t i = 0; i < size; i++)
            if (m[row][i] == m[row][col] && i != col)
                return false;

        // column constraint
        for (uint32_t i = 0; i < size; i++)
            if (m[i][col] == m[row][col] && i != row)
                return false;

        // box constraint
        uint32_t r = row / box_size * box_size;
        uint32_t c = col / box_size * box_size;

        for (uint32_t i = 0; i < box_size; i++)
            for (uint32_t j = 0; j < box_size; j++)
                if (m[r + i][c + j] == m[row][col] && r + i != row && c + j != col)
                    return false;

        return true;
    }

    bool problem96::sudoku::solve(uint32_t row, uint32_t col) {
        // std::cout << "Solve " << row << ", " << col << std::endl;
        if (m[row][col] != 0) { // if m[row][col] is a hint, skip to next element
            if (col == size - 1)
                return row == size - 1 || solve(row + 1, 0);
            else
                return solve(row, col + 1);
        } else { // try all values 1 to 9 and solve recursively
            // std::cout << "Recursive solve " << row << ", " << col << std::endl;
            for (uint32_t i = 1; i <= size; i++) {
                m[row][col] = i;

                if (!is_valid_value(row, col))
                    continue;

                if (col == size - 1 && (row == size - 1 || solve(row + 1, 0)))
                    return true;
                else if (col < size - 1 && solve(row, col + 1))
                    return true;
            }

            // if no value allow for a valid solution set empty and return unsolvable;
            m[row][col] = 0;
            return false;
        }
    }

    const vector<uint32_t>& problem96::sudoku::operator[](uint32_t index) {
        return m[index];
    }


    uint32_t problem96::solve() {
        uint32_t result = 0;

        vector<vector<uint32_t>> vectors = read_matrix<uint32_t>(problems_folder + "51-100/96/input.txt");

        for (const auto& vector : vectors) {
            sudoku s(vector);
            s.solve();

            result += s[0][0] * 100;
            result += s[0][1] * 10;
            result += s[0][2];
        }

        return result;
    }
}