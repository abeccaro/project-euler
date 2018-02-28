//
// Created by Alex Beccaro on 25/01/18.
//

#include "problem82.hpp"
#include <input.hpp>
#include <queue>

using input::read_matrix;
using std::priority_queue;

namespace problems {
    problem82::entry::entry(ulong row, ulong col, uint value) :
            row(row), col(col), value(value), distance(numeric_limits<uint>::max()) {};

    bool problem82::entry_comparer::operator()(const entry* a, const entry* b) {
        return a->distance > b->distance;
    };

    uint problem82::best_path_sum(const vector<vector<uint>>& matrix) {
        priority_queue<entry*, std::vector<entry*>, entry_comparer> q;
        vector<vector<entry*>> entries(matrix.size());

        // entries matrix initialization
        for (uint r = 0; r < entries.size(); r++) {
            entries[r] = vector<entry*>(matrix[r].size());
            for (uint c = 0; c < entries[r].size(); c++)
                entries[r][c] = new entry(r, c, matrix[r][c]);
        }

        // first column entries processed and inserted in queue
        for (uint i = 0; i < entries.size(); i++) {
            entries[i][0]->distance = entries[i][0]->value;
            q.push(entries[i][0]);
        }

        // main loop that expands paths from each element in queue to their allowed neighbours.
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
        }

        // returning sum of numbers in best path
        uint min_distance = 1000000;
        for (uint i = 0; i < entries.size(); i++) {
            min_distance = min(min_distance, entries[i].back()->distance);
            for (const auto& e : entries[i])
                delete e;
        }

        return min_distance;
    }

    uint problem82::solve() {
        vector<vector<uint>> matrix = read_matrix<uint>(input::PROBLEMS_FOLDER + "51-100/82/input.txt");

        return best_path_sum(matrix);
    }
}