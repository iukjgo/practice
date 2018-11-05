

#include <iostream>
#include <vector>
#include <algorithm>
#include "KeyPair.h"
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        int x;
        cin >> n >> x;
        
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];
        
        KeyPairSolver test;
        
        test.setArrayToSolve(a);
        
        
        if (test.pairExistsBruteForce(x))
            cout << "Yes";
        else
            cout << "No";
        
        cout << endl;
        
        bool t3 = false;
        
    }
    return 0;
}
