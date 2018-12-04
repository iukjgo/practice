#ifndef MAX_TIP_CALC_H
#define MAX_TIP_CALC_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class MaxTipCalc
{
public:
    MaxTipCalc(vector<int>& a, vector<int>& b, int x, int y) : mX(x), mY(y), mA(a), mB(b) {};
    int solve();

private:

    int solveHelper(int pos, int x, int y);

    vector<int> mA;
    vector<int> mB;
    int mX;
    int mY;

    unordered_map<string, int> testCache;

};

#endif /* MAX_TIP_CALC_H */
