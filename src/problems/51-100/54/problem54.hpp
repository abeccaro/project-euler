//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM54_HPP
#define PROJECT_EULER_PROBLEM54_HPP

#include "vector"
#include "string"

namespace problems {
    class problem54 {
    private:
        /**
         * Card representation.
         * All public for simplicity.
         */
        struct card {
            /**
             * Suits enumeration
             */
            enum suit_t {diamonds, clubs, hearts, spades};

            suit_t suit;  // the suit
            uint32_t value; // the value

            /**
             * Constructor from string (as in input file)
             * @param s The string representation of the card
             */
            explicit card(std::string s);

            /**
             * Operator < definition for sorting cards
             * @param other The other card
             * @return true if this card comes before the other card
             */
            bool operator <(const card& other) const;
        };

        /**
         * A player's hand representation.
         * All public for simplicity.
         */
        struct hand {
            std::vector<card> cards; // cards in hand

            /**
             * Adds a card to this hand
             * @param c The card to add
             */
            void add(const card &c);

            /**
             * Compares this hand with given one and returns true if this is better.
             * @param other The other hand
             * @return true if this hand is better than the other one, false otherwise
             */
            bool operator>(hand &other);

            /**
             * Calculates a score for this hand. Absolute values may vary a lot but order is maintained.
             * @return The score of this hand
             */
            uint32_t score();

            /**
             * Checks if this hand is a flush
             * @return true if this hand is a flush, false otherwise
             */
            bool is_flush() const;

            /**
             * Checks if this hand is a straight. Cards are assumed to be ordered by value
             * @return true if this hand is a straight, false otherwise
             */
            bool is_straight() const;
        };
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM54_HPP
