#include "MaxTipCalc.h"

#include <algorithm>
#include <string>

int MaxTipCalc::solve() {
   
    return solveHelper(0, mX, mY);
}

int MaxTipCalc::solveHelper(int pos, int x, int y) {

    if (pos >= mA.size())
        return 0;

    string key = to_string(pos) + '&' + to_string(x) + '&' + to_string(y);
    if (testCache.find(key) != testCache.end()) {
        return testCache[key];
    }

    int maxA = -1;
    int maxB = -1;
    if (x > 0)
        maxA = mA[pos] + solveHelper(pos + 1, x - 1, y);

    if (y > 0)
        maxB = mB[pos] + solveHelper(pos + 1, x, y - 1);

    int max;
    if (maxA > maxB)
        max = maxA;
    else
        max = maxB;

    testCache[key] = max;
    return max
}

