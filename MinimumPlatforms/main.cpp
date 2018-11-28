#include <iostream>
#include <vector>

using namespace std;

int main() {
   int T;
   cin >> T;

   while (T--) {
      int N;
      cin >> N;
      vector<int> arrivals(N);
      vector<int> departures(N);

      for (int i = 0; i < N; i++) {
         cin >> arrivals[i];
      }

      for (int i = 0; i < N; i++) {
         cin >> departures[i];
      }


      /* SOLVE */


   }
   return 0;
}