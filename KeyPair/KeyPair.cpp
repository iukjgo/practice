#include "KeyPair.h"

void KeyPairSolver::setArrayToSolve(std::vector<int>& array)
{
    mArray = array;
    std::sort(mArray.begin(), mArray.end());
}

bool KeyPairSolver::pairExists(int x)
{
    int l = 0;
    int r = (int)mArray.size() - 1;
    
    while (l < r) {
        int testValue = mArray[r] + mArray[l];
        if (testValue == x)
            return true;
        else if (testValue > x)
            r--;
        else
            l++;
    }
    return false;
}

bool KeyPairSolver::pairExistsBruteForce(int x)
{
    for (int i=0; i<mArray.size(); i++) {
        for (int j=i+1; j<mArray.size(); j++) {
            if (mArray[i] + mArray[j] == x) {
                return true;
            }
        }
    }

    return false;
}
