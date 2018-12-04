#ifndef MAX_TIP_CALC_H
#define MAX_TIP_CALC_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Tips {
public:
    Tips(int a, int b) : mA(a), mB(b), mDiff(abs(a-b)) {};

    bool operator < (const Tips& right) const {
        return this->diff() < right.diff();
    }

    const int a() const { return mA; }
    const int b() const { return mB; }
    const int diff() const { return mDiff; }

private:
    int mA;
    int mB;
    int mDiff;
};



class MaxTipCalc
{
public:
    MaxTipCalc(vector<int>& a, vector<int>& b, int x, int y) : mX(x), mY(y), mA(a), mB(b) {};
    int solve();

private:

    int solveDP(int pos, int x, int y);
    int solveGreedy();

    vector<int> mA;
    vector<int> mB;
    int mX;
    int mY;

    unordered_map<string, int> testCache;

};

#endif /* MAX_TIP_CALC_H */
