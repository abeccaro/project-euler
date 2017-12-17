//
// Created by Alex Beccaro on 12/12/17.
//
#ifndef PROJECT_EULER_INPUT_H
#define PROJECT_EULER_INPUT_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

namespace input {
    const string project_path = "/Users/Becks/Programmazione/project-euler/";

    /**
     * Reads a vector of numbers from specified file.
     * @param filename The path of input file
     * @return the vector of ints
     */
    template<class T>
    vector<T> read_vector(const string &filename) {
        vector<T> numbers;
        ifstream file(filename);

        string line;
        while (file >> line) {
            stringstream line_stream(line);

            T n;
            while (line_stream >> n)
                numbers.push_back(n);
        }

        file.close();

        return numbers;
    }

    /**
     * Reads a matrix of numbers from specified file.
     * @param filename The path of input file
     * @return The matrix of ints
     */
    template<class T>
    vector<vector<T>> read_matrix(const string &filename) {
        vector<vector<T>> matrix;
        ifstream file(filename);

        string line;
        while(getline(file, line)) {
            vector<T> row;
            stringstream line_stream(line);

            T n;
            while(line_stream >> n)
                row.push_back(n);

            matrix.push_back(row);
        }

        file.close();

        return matrix;
    }
}

#endif //PROJECT_EULER_INPUT_H