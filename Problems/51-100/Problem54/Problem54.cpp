//
// Created by Alex Beccaro on 09/01/18.
//

#include <iostream>
#include <input.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace input;

using numtype = unsigned int;

/**
 * Suits enumeration
 */
enum suit { diamonds, clubs, hearts, spades };

/**
 * Card representation.
 * All public for simplicity.
 */
struct card {
public:
    suit suit; // the suit
    unsigned int value; // the value

    card() = default;

    /**
     * Constructor from string (as in input file)
     * @param s The string representation of the card
     */
    explicit card(string s) {
        switch (s[0]) {
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                value = (unsigned int) s[0] - 48;
                break;
            case 'T':
                value = 10;
                break;
            case 'J':
                value = 11;
                break;
            case 'Q':
                value = 12;
                break;
            case 'K':
                value = 13;
                break;
            case 'A':
                value = 14;
        }

        switch (s[1]) {
            case 'D':
                suit = diamonds;
                break;
            case 'C':
                suit = clubs;
                break;
            case 'H':
                suit = hearts;
                break;
            case 'S':
                suit = spades;
        }
    }

    /**
     * Operator < definition for sorting cards
     * @param other The other card
     * @return true if this card comes before the other card
     */
    bool operator <(const card& other) const {
        return value < other.value;
    }
};

/**
 * A player's hand representation.
 * All public for simplicity.
 */
struct hand {
public:
    vector<card> cards; // cards in hand

    /**
     * Adds a card to this hand
     * @param c The card to add
     */
    void add(const card& c) {
        cards.push_back(c);
    }

    /**
     * Compares this hand with given one and returns true if this is better.
     * @param other The other hand
     * @return true if this hand is better than the other one, false otherwise
     */
    bool operator >(hand& other) {
        return score() > other.score();
    }

    /**
     * Calculates a score for this hand. Absolute values may vary a lot but order is maintained.
     * @return The score of this hand
     */
    unsigned int score() {
        sort(cards.begin(), cards.end());
        unsigned int hc = cards.back().value;
        bool s = is_straight();
        bool f = is_flush();

        if (s && f) {
            if (hc == 14)
                return 10000; // Royal flush
            return 9999; // Straight flush
        }

        if (f)
            return 9499; // Flush

        if (s)
            return 9498; // Straight

        // counting repetitions (poker, tris and couples)
        unsigned int n_v1 = 0, v1, n_v2 = 0, v2;
        for (unsigned int i = 2; i < 15; i++) {
            unsigned int c = count_if(cards.begin(), cards.end(), [i](card c){return c.value == i;});
            if (c > n_v1 || (c == n_v1 && i > v1)) {
                if (n_v1 > 0) {
                    n_v2 = n_v1;
                    v2 = v1;
                }
                n_v1 = c;
                v1 = i;
            } else if (c > n_v2 || (c == n_v2 && i > v2)) {
                n_v2 = c;
                v2 = i;
            }
        }

        if (n_v1 == 4)
            return 9500 + v1 + 14 + hc; // Poker

        if (n_v1 == 1)
            return hc; // High card

        if (n_v1 == 3) {
            if (n_v2 == 2)
                return 9000 + v1 + 14 + v2; // Full house
            else
                return 8000 + hc; // Tris
        }

        if (n_v2 == 2)
            return 7000 + v1 + 14 + v2; // Double pair

        return 6000 + v1; // Pair
    }

    /**
     * Checks if this hand is a flush
     * @return true if this hand is a flush, false otherwise
     */
    bool is_flush() const {
        suit s = cards[0].suit;
        for (auto i = cards.begin() + 1; i < cards.end(); i++)
            if (i->suit != s)
                return false;
        return true;
    }

    /**
     * Checks if this hand is a straight
     * @return true if this hand is a straight, false otherwise
     */
    bool is_straight() const {
        for (unsigned int i = 1; i < 5; i++)
            if (cards[i-1].value != cards[i].value - 1)
                return false;
        return true;
    }
};

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    timer::time_point start = timer::now();

    numtype result = 0;

    vector<vector<string>> cards = read_matrix<string>(PROJECT_PATH + "Problems/51-100/Problem54/input.txt");
    vector<hand> hands(cards.size() * 2);

    for (unsigned int i = 0; i < hands.size(); i++)
        for (unsigned int j = 0; j < 5; j++)
            hands[i].add((card) cards[i / 2][i % 2 == 0 ? j : j + 5]);

    for (int i = 0; i < hands.size(); i += 2)
        if (hands[i] > hands[i+1])
            result++;

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The number of winning hands for player 1 is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}