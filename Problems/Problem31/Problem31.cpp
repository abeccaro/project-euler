//
// Created by Alex Beccaro on 18/12/17.
//

#include <iostream>
#include <vector>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;

using numtype = unsigned int;

/**
 * Counts the possible different ways in which 'pence' pence can be obtained using coins equal or less valuable than
 * given one.
 * Function can be improved by using memoization.
 * @param pence The pence to make
 * @param coin The maximum value coin to use
 * @return The number of different ways to make 'pence' pence
 */
numtype coins_combination(const numtype &pence, const vector<const numtype>::iterator &coin) {
    if (*coin == 1)
        return 1;

    numtype count = 0;
    for (numtype i = 0; i <= pence / (*coin); i++) {
        numtype remaining = pence - i * (*coin);
        count += coins_combination(remaining, (coin + 1));
    }
    return count;
}

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    const numtype PENCE = 200;
    vector<const numtype> coins = {200, 100, 50, 20, 10, 5, 2, 1};

    timer::time_point start = timer::now();

    numtype result = coins_combination(PENCE, coins.begin());

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The number of different ways in which " << PENCE << "p can be made using any number of coins is "
         << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}