//
// Created by Alex Beccaro on 12/12/17.
//
#ifndef PROJECT_EULER_INPUT_H
#define PROJECT_EULER_INPUT_H

#include "vector"
#include "string"
#include "fstream"
#include "sstream"
#include "boost/multiprecision/cpp_int.hpp"
#include "template_conditions.hpp"

namespace input {
    const std::string problems_folder = "../src/problems/";

    /**
     * Reads a vector of elements from specified file.
     * @param filename The path of input file
     * @return the vector of elements
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value ||
            std::is_convertible<T, std::string>::value>::type>
    std::vector<T> read_vector(const std::string &filename);

    /**
     * Reads a matrix of elements from specified file.
     * @param filename The path of input file
     * @return The matrix of elements
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value ||
            std::is_convertible<T, std::string>::value>::type>
    std::vector<std::vector<T>> read_matrix(const std::string &filename);
}

#include "input.ipp"

#endif //PROJECT_EULER_INPUT_H