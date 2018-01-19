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
#include "template_conditions.hpp"

using namespace std;
using namespace template_conditions;

namespace input {
    const string PROBLEMS_FOLDER = "/Users/Becks/Programmazione/project-euler/src/problems/";

    /**
     * Reads a vector of elements from specified file.
     * @param filename The path of input file
     * @return the vector of elements
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value || is_convertible<T, string>::value>::type>
    vector<T> read_vector(const string &filename) {
        vector<T> numbers;
        ifstream file(filename);
        assert(file && "Specified file does not exist");

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
     * Reads a matrix of elements from specified file.
     * @param filename The path of input file
     * @return The matrix of elements
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value || is_convertible<T, string>::value>::type>
    vector<vector<T>> read_matrix(const string &filename) {
        vector<vector<T>> matrix;
        ifstream file(filename);
        assert(file && "Specified file does not exist");

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