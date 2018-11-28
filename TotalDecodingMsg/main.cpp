#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "TDM.h"
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        
        TDM test;
        test.setMessageToSolve(s);
        int result = test.solve();
        
        cout << to_string(result) << endl;
    }
    return 0;
}
