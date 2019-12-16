//
// Created by Alex Beccaro on 09/01/18.
//

#include "problem54.hpp"
#include <input.hpp>

using std::vector;
using std::string;

using input::read_matrix;
using input::problems_folder;

namespace problems {
    problem54::card::card(string s) {
        switch (s[0]) {
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                value = (uint32_t) s[0] - 48;
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

    bool problem54::card::operator<(const card &other) const {
        return value < other.value;
    }

    void problem54::hand::add(const card &c) {
        cards.push_back(c);
    }

    bool problem54::hand::operator>(hand &other) {
        return score() > other.score();
    }

    uint32_t problem54::hand::score() {
        sort(cards.begin(), cards.end());
        uint32_t hc = cards.back().value;
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
        uint32_t n_v1 = 0, v1 = 0, n_v2 = 0, v2 = 0;
        for (uint32_t i = 2; i < 15; i++) {
            uint32_t c = count_if(cards.begin(), cards.end(), [i](card c) { return c.value == i; });
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

    bool problem54::hand::is_flush() const {
        card::suit_t s = cards[0].suit;
        for (auto i = cards.begin() + 1; i < cards.end(); i++)
            if (i->suit != s)
                return false;
        return true;
    }

    bool problem54::hand::is_straight() const {
        for (uint32_t i = 1; i < 5; i++)
            if (cards[i - 1].value != cards[i].value - 1)
                return false;
        return true;
    }

    uint32_t problem54::solve() {
        vector<vector<string>> cards = read_matrix<string>(problems_folder + "51-100/54/input.txt");
        vector<hand> hands(cards.size() * 2);

        for (uint32_t i = 0; i < hands.size(); i++)
            for (uint32_t j = 0; j < 5; j++)
                hands[i].add((card) cards[i / 2][i % 2 == 0 ? j : j + 5]);

        uint32_t result = 0;
        for (int i = 0; i < hands.size(); i += 2)
            if (hands[i] > hands[i + 1])
                result++;
        return result;
    }
}