//
//  TDM.cpp
//
//  Created by Abraham Kim on 2018/11/07.
//

#include "TDM.h"

void
TDM::setMessageToSolve(std::string s)
{
   mCountCache = std::unordered_map<int,int>();
   mStr = s;
   mValid = false;
   /*
   bool leadingZeroes = false;
   bool trailingZeroes= false;
   bool consecutiveZeroes = false;
   */
   if (s.length() > 0) {
      if (s[0] == '0')
         return;
   }

   char prev = '0';

   for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
         if (prev != '1' && prev != '2') return;
      }
      prev = s[i];
   }

   mValid = true;
}

int
TDM::solve()
{
   if (!mValid)
      return 0;

   if (mStr.length() < 2)
      return 1;


   return getDecodePossibilityCountIterative();
}

int
TDM::getDecodePossibilityCount(int strtPos)
{
   if (strtPos >= mStr.length())
      return 1;

   int count = 0;

   if (mStr[strtPos] != '0') {
      // one char
      count += getDecodePossibilityCount(strtPos + 1);

      // try two chars
      if (strtPos + 1 < mStr.length()) {
         if (mStr[strtPos] == '1' ||
            (mStr[strtPos] == '2' && mStr[strtPos + 1] >= '0' && mStr[strtPos + 1] <= '6')) {
            // between [10~26]
            count += getDecodePossibilityCount(strtPos + 2);
         }
      }
   }
   return count;
}


int
TDM::getDecodePossibilityCountIterative()
{
   for (int i = mStr.length()-1; i >= 0; i--) {
      if (mStr[i] > '0') {
      }
   }

   if (strtPos >= mStr.length())
      return 1;

   int count = 0;

   if (mStr[strtPos] != '0') {
      // one char
      count += getDecodePossibilityCount(strtPos + 1);

      // try two chars
      if (strtPos + 1 < mStr.length()) {
         if (mStr[strtPos] == '1' ||
            (mStr[strtPos] == '2' && mStr[strtPos + 1] >= '0' && mStr[strtPos + 1] <= '6')) {
            // between [10~26]
            count += getDecodePossibilityCount(strtPos + 2);
         }
      }
   }
   return count;
}
/*
1 2 3 5
12 3 5
1 23 5
*/
