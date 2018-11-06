

#include <iostream>
#include <vector>
#include <algorithm>
#include "KnightWalk.h"
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        int m;
        int s1, s2, d1, d2;
        cin >> n >> m >> s1 >> s2 >> d1 >> d2;
        
        KnightWalk test;
        test.setBoardToSolve(n, m);
        int result = test.solve(s1-1, s2-1, d1-1, d2-1); // implementation is zero-based whereas input is one-based
        
        cout << std::to_string(result) << endl;
    }
    return 0;
}
