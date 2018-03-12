//
// Created by Alex Beccaro on 12/03/18.
//

#include "problem96.hpp"
#include <input.hpp>

namespace problems {
    problem96::sudoku::sudoku(uint size) : size(size), box_size((uint) sqrt(size)) {
        m = vector<vector<uint>>(size);
        for (auto& row : m)
            row = vector<uint>(size);
    }

    problem96::sudoku::sudoku(const vector<uint>& v) : size((uint) sqrt(v.size())), box_size((uint) sqrt(size)) {
        m = vector<vector<uint>>(size);
        for (auto& row : m)
            row = vector<uint>(size);

        for (uint i = 0; i < size; i++)
            for (uint j = 0; j < size; j++)
                m[i][j] = v[i * size + j];
    }

    bool problem96::sudoku::is_valid_value(uint row, uint col) {
        // row constraint
        for (uint i = 0; i < size; i++)
            if (m[row][i] == m[row][col] && i != col)
                return false;

        // column constraint
        for (uint i = 0; i < size; i++)
            if (m[i][col] == m[row][col] && i != row)
                return false;

        // box constraint
        uint r = row / box_size * box_size;
        uint c = col / box_size * box_size;

        for (uint i = 0; i < box_size; i++)
            for (uint j = 0; j < box_size; j++)
                if (m[r + i][c + j] == m[row][col] && r + i != row && c + j != col)
                    return false;

        return true;
    }

    bool problem96::sudoku::solve(uint row, uint col) {
        if (m[row][col] != 0) { // if m[row][col] is a hint, skip to next element
            if (col == size - 1)
                return row == size - 1 || solve(row + 1, 0);
            else
                return solve(row, col + 1);
        } else { // try all values 1 to 9 and solve recursively
            for (uint i = 1; i <= size; i++) {
                m[row][col] = i;

                if (!is_valid_value(row, col))
                    continue;

                if (col == size - 1 && (row == size - 1 || solve(row + 1, 0)))
                    return true;
                else if (solve(row, col + 1))
                    return true;
            }

            // if no value allow for a valid solution set empty and return unsolvable;
            m[row][col] = 0;
            return false;
        }
    }

    const vector<uint>& problem96::sudoku::operator[](uint index) {
        return m[index];
    }


    uint problem96::solve() {
        uint result = 0;

        vector<vector<uint>> vectors = input::read_matrix<uint>(input::PROBLEMS_FOLDER + "51-100/96/input.txt");
        vector<sudoku> sudokus(vectors.size());

        for (uint i = 0; i < vectors.size(); i++)
            sudokus[i] = sudoku(vectors[i]);

        for (auto& s : sudokus) {
            s.solve();

            result += s[0][0] * 100;
            result += s[0][1] * 10;
            result += s[0][2];
        }

        return result;
    }
}