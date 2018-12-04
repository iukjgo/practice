#include "MaxTipCalc.h"

#include <algorithm>
#include <string>

int MaxTipCalc::solve() {
   
    //return solveDP(0, mX, mY);
    return solveGreedy();
}

int MaxTipCalc::solveDP(int pos, int x, int y) {

    if (pos >= mA.size())
        return 0;

    string key = to_string(pos) + '&' + to_string(x) + '&' + to_string(y);
    if (testCache.find(key) != testCache.end()) {
        return testCache[key];
    }

    int maxA = -1;
    int maxB = -1;
    if (x > 0)
        maxA = mA[pos] + solveDP(pos + 1, x - 1, y);

    if (y > 0)
        maxB = mB[pos] + solveDP(pos + 1, x, y - 1);

    int max;
    if (maxA > maxB)
        max = maxA;
    else
        max = maxB;

    testCache[key] = max;
    return max;
}

int MaxTipCalc::solveGreedy() {
    vector<Tips> test;
    int x = mX;
    int y = mY;

    for (int i = 0; i < mA.size(); i++) {
        test.push_back(Tips(mA[i], mB[i]));
    }

    sort(test.begin(), test.end());

    int max = 0;
    for (int i = mA.size()-1; i >= 0; i--) {
        Tips t = test[i];

        
        if (x > 0 && t.a() >= t.b()) {
            max += t.a();
            x--;
        }
        else if (y > 0 && t.a() <= t.b() ){
            max += t.b();
            y--;
        }
        else {
            if (x==0) max+=t.b();
            else max+=t.a();
        }
    }

    return max;
}