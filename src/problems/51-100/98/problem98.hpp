//
// Created by Alex Beccaro on 13/03/18.
//

#ifndef PROJECT_EULER_PROBLEM98_HPP
#define PROJECT_EULER_PROBLEM98_HPP

#include "cstdint"
#include "string"
#include "vector"

namespace problems {
    class problem98 {
    private:
        /**
         * Tries to match first word with given square. If it succeeds it returns the corresponding value for the second
         * word. Words are supposed to be anagrams.
         * @param p The pair of words
         * @param square The square to match with first word
         * @return The value of second word if match succeeds, 0 otherwise
         */
        static uint32_t match(std::pair<std::string, std::string> p, uint32_t square);

        /**
         * Calculates the maximum square value obtained by substituting digits to letters in such a way that both words
         * produce squares and same letter means same digit. Words are supposed to be anagrams.
         * @param p The pair of words
         * @param squares The possible squares to test for first word
         * @return The maximum square if p is a square anagram word pair, 0 otherwise
         */
        static uint32_t max_pair_square(const std::pair<std::string, std::string>& p,
                                        const std::vector<uint32_t>& squares);

        /**
         * Checks if given strings are anagrams
         * @param w1 The first string
         * @param w2 The second string
         * @return True if they are anagrams, false otherwise
         */
        static bool is_anagram_pair(const std::string& w1, const std::string& w2);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM98_HPP
