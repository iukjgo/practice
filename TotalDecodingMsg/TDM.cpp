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
      if (s[s.length()-1] == '0')
         return;
   }

   bool prevZero = false;

   for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
         if (prevZero) return;
         prevZero = true;
      }
      else {
         prevZero = false;
      }
   }

   mValid = true;
}

int
TDM::solve()
{
   if (!mValid)
      return -1;

   if (mStr.length() < 2)
      return 1;


   return getDecodePossibilityCount(0);
}

int
TDM::getDecodePossibilityCount(int strtPos)
{
   if (strtPos >= mStr.length())
      return 0;

   std::unordered_map<int,int>::iterator itr = mCountCache.find(strtPos);
   if (itr != mCountCache.end())
      return itr->second;

   int count = 0;
   // one char 
   count++;
   count += getDecodePossibilityCount(strtPos + 1);

   // try two chars
   if (strtPos + 1 < mStr.length()) {
      if (mStr[strtPos] == '1' ||
         (mStr[strtPos] == '2' && mStr[strtPos + 1] >= '0' && mStr[strtPos + 1] <= '6')) {
         // between [10~26]
         count++;
         count += getDecodePossibilityCount(strtPos + 1);
      }
   }
   mCountCache[strtPos] = count;
   return count;
}