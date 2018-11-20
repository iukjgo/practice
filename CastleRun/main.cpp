#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include "CastleRun.h"
using namespace std;

int main() {
   int T=0;
   cin >> T;
   vector<vector<int>> arrays;
   vector<int> ks(T);

   for (int i=0; i<T; i++) {
      int n = 0;
      int k = 0;
      cin >> n >> k;
        
      vector<int> array(n);
      ks[i] = k;
      for (int j=0; j<n; j++) {
         cin >> array[j];
      }

      arrays.push_back(array);
   }
    
   for (int i=0; i<T; i++) {
      FourNums solver;
      solver.setArrayToSolve(arrays[i]);
      vector<string> results = solver.solveGeneric(ks[i]);

      for (int j=0; j<results.size(); j++)
         cout << results[i] << "$";
      if (results.size() == 0)
         cout << "-1";

      cout << endl;
   }
    

    
    return 0;
}
