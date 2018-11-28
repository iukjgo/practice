#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<int, int> left, pair<int, int> right) {
   return left.second < right.second;
}

int main() {
   int T;
   cin >> T;

   while (T--) {
      int N;
      cin >> N;
      vector<pair<int,int>> times(N);

      for (int i = 0; i < N; i++) {
         cin >> times[i].first;
      }

      for (int i = 0; i < N; i++) {
         cin >> times[i].second;
      }

      sort(times.begin(), times.end(), compare);
      int maxPlatforms = 1;
      for (int i = 0; i < N; i++) {
         int a = times[i].first;

         int platforms = 1;
         for (int j = i - 1; j >= 0; j--) {
            int b1 = times[j].first;
            int b2 = times[j].second;
            if (a >= b1 && a < b2)
               platforms++;
            else
               break;
         }
         if (platforms > maxPlatforms)
            maxPlatforms = platforms;
      }

      cout << to_string(maxPlatforms) << endl;


   }
   return 0;
}