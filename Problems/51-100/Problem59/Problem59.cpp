//
// Created by Alex Beccaro on 11/01/18.
//

#include <iostream>
#include <input.hpp>

using namespace std;
using namespace chrono;
using timer = high_resolution_clock;
using namespace input;

using numtype = unsigned int;

/**
 * Specifies values, solves problem and outputs solution and calculation time.
 * @return The exit code
 */
int main() {
    timer::time_point start = timer::now();

    vector<numtype> words = read_vector<numtype>(PROJECT_PATH + "Problems/51-100/Problem59/input.txt");
    string pw = "___";
    numtype result, max_letters = 0;

    for (char c1 = 'a'; c1 <= 'z'; c1++) {
        pw[0] = c1;
        for (char c2 = 'a'; c2 <= 'z'; c2++) {
            pw[1] = c2;
            for (char c3 = 'a'; c3 <= 'z'; c3++) {
                pw[2] = c3;

                numtype letters = 0, sum = 0;
                for (numtype i = 0; i < words.size(); i++) {
                    char c = pw[i % 3] ^ words[i];
                    if (c >= 'a' && c <= 'z')
                        letters++;
                    sum += c;
                }

                if (letters > max_letters) {
                    result = sum;
                    max_letters = letters;
                }
            }
        }
    }

    double time = duration_cast<microseconds>(timer::now() - start).count() / 1000000.0;

    cout << "The sum of the ASCII values in the original text is " << result << endl;
    cout << "Calculation took " << time << " seconds" << endl;
}