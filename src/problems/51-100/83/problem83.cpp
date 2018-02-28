//
// Created by Alex Beccaro on 28/01/18.
//

#include "problem83.hpp"
#include <input.hpp>
#include <queue>

using input::read_matrix;
using std::priority_queue;

namespace problems {
    problem83::entry::entry(ulong row, ulong col, uint value) :
            row(row), col(col), value(value), distance(numeric_limits<uint>::max()) {};

    bool problem83::entry_comparer::operator()(const entry* a, const entry* b) {
        return a->distance > b->distance;
    };

    uint problem83::best_path_sum(const vector<vector<uint>>& matrix) {
        priority_queue<entry*, std::vector<entry*>, entry_comparer> q;
        vector<vector<entry*>> entries(matrix.size());

        // entries matrix initialization
        for (uint r = 0; r < entries.size(); r++) {
            entries[r] = vector<entry*>(matrix[r].size());
            for (uint c = 0; c < entries[r].size(); c++)
                entries[r][c] = new entry(r, c, matrix[r][c]);
        }

        // first entry processed and inserted in queue
        entries[0][0]->distance = entries[0][0]->value;
        q.push(entries[0][0]);

        // main loop that expands paths from each element in queue to their neighbours.
        // updated (improved) neighbours are inserted to queue to expand again recursively.
        while (!q.empty()) {
            entry* e = q.top();
            q.pop();

            // down
            if (e->row < entries.size() - 1) {
                entry* down = entries[e->row + 1][e->col];
                if (down->distance > e->distance + down->value) {
                    down->distance = e->distance + down->value;
                    q.push(down);
                }
            }

            // right
            if (e->col < entries[e->row].size() - 1) {
                entry* right = entries[e->row][e->col + 1];
                if (right->distance > e->distance + right->value) {
                    right->distance = e->distance + right->value;
                    q.push(right);
                }
            }

            // up
            if (e->row > 0) {
                entry* up = entries[e->row - 1][e->col];
                if (up->distance > e->distance + up->value) {
                    up->distance = e->distance + up->value;
                    q.push(up);
                }
            }

            // left
            if (e->col > 0) {
                entry* left = entries[e->row][e->col - 1];
                if (left->distance > e->distance + left->value) {
                    left->distance = e->distance + left->value;
                    q.push(left);
                }
            }
        }

        // returning sum of numbers in best path
        uint result = entries.back().back()->distance;

        // deleting pointers
        for (const auto& es : entries)
            for (const auto& e : es)
                delete e;

        return result;

    }

    uint problem83::solve() {
        vector<vector<uint>> matrix = read_matrix<uint>(input::PROBLEMS_FOLDER + "51-100/83/input.txt");

        return best_path_sum(matrix);
    }
}