#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include "MaxTipCalc.h"
using namespace std;

int main() {
    int T=0;
    cin >> T;

    while (T--) {
        int N;
        int X, Y;
        
        cin >> N;
        cin >> X >> Y;
        
        vector<int> A(N);
        vector<int> B(N);
        
        for (int i=0; i<N; i++) {
            cin >> A[i];
        }
        for (int i=0; i<N; i++) {
            cin >> B[i];
        }
        MaxTipCalc test(A, B, X, Y);
        cout << test.solve() << endl;

    }

    return 0;
}
