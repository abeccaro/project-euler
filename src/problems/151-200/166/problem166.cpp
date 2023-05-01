//
// Created by Alex Beccaro on 01/05/2023.
//

#include "problem166.hpp"


namespace problems {
    uint32_t problem166::solve() {
        uint32_t result = 0;

        // every solution with 0,1,2,3,4 in first cell has a 5,6,7,8,9 complementary one
        // so search only half the space and multiply result by 2 at the end
        for (int32_t a1 = 0; a1 < 5; a1++) {
            for (int32_t a2 = 0; a2 < 10; a2++) {
                for (int32_t a3 = 0; a3 < 10; a3++) {
                    for (int32_t a4 = 0; a4 < 10; a4++) {
                        // calculate sum
                        int32_t sum = a1 + a2 + a3 + a4;

                        for (int32_t a5 = 0; a5 < 10; a5++) {
                            for (int32_t a9 = 0; a9 < 10; a9++) {
                                // calculate and check a13
                                int32_t a13 = sum - a1 - a5 - a9;
                                if (a13 > 9)
                                    continue;
                                if (a13 < 0)
                                    break;

                                for (int32_t a7 = 0; a7 < 10; a7++) {
                                    // calculate and check a10
                                    int32_t a10 = sum - a4 - a7 - a13;
                                    if (a10 > 9)
                                        continue;
                                    if (a10 < 0)
                                        break;

                                    for (int32_t a6 = 0; a6 < 10; a6++) {
                                        // calculate and check a8
                                        int32_t a8 = sum - a5 - a6 - a7;
                                        if (a8 > 9)
                                            continue;
                                        if (a8 < 0)
                                            break;

                                        // calculate and check a14
                                        int32_t a14 = sum - a2 - a6 - a10;
                                        if (a14 > 9)
                                            continue;
                                        if (a14 < 0)
                                            break;

                                        for (int32_t a11 = 0; a11 < 10; a11++) {
                                            // calculate and check a12
                                            int32_t a12 = sum - a9 - a10 - a11;
                                            if (a12 > 9)
                                                continue;
                                            if (a12 < 0)
                                                break;

                                            // calculate and check a15
                                            int32_t a15 = sum - a3 - a7 - a11;
                                            if (a15 > 9)
                                                continue;
                                            if (a15 < 0)
                                                break;

                                            // calculate and check a16
                                            int32_t a16 = sum - a1 - a6 - a11;
                                            if (a16 > 9)
                                                continue;
                                            if (a16 < 0)
                                                break;

                                            if (a4 + a8 + a12 + a16 == sum && a13 + a14 + a15 + a16 == sum)
                                                result++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return result * 2;
    }
}