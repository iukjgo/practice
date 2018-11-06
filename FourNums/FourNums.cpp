#include "FourNums.h"

#include <algorithm>
#define INT_MIN -100000
void
FourNums::setArrayToSolve(std::vector<int>& array)
{
   mArray = array;
   std::sort(mArray.begin(), mArray.end());
   mInclude = std::vector<bool>(mArray.size(), false);
}

std::vector<std::string>
FourNums::solveGeneric(int goalValue)
{

   bool found = false;
   int prev = INT_MIN;
   for (int pos = 0; pos<mArray.size(); pos++) {
      if (prev == mArray[pos])
         continue;

      prev = mArray[pos];

      mInclude[pos] = true;
      if (findGroups(goalValue-mArray[pos], mNumOfElements-1, pos+1)) {
         found = true;
      }
      mInclude[pos] = false;
   }

   return mResults;
}


bool
FourNums::findGroups(int goalValue, int numOfElements, int pos)
{
   bool found = false;
   if (goalValue > 0) {
      if (numOfElements > 0) {
         int prev = INT_MIN;
         
         for (int i = pos; i<mArray.size(); i++) {
            if (prev == mArray[i])
               continue;

            prev = mArray[i];

            mInclude[i] = true;
            /*if (goalValue - mArray[i] < 0) {
               mInclude[i] = false;
               break; // no need to try more at this point
            }
            else */
            if (findGroups(goalValue - mArray[i], numOfElements - 1, i + 1)) {
               found = true;
            }
            mInclude[i] = false;
         }
      }
   }
   else if (goalValue == 0) {
      if (numOfElements == 0) {
         registerGroup();
         found = true;
      }
   }
   else {
      // value over
      found = false;
   }

   return found;
}


void
FourNums::registerGroup()
{
   std::string group;
   for (int i = 0; i<mArray.size(); i++) {
      if (mInclude[i]) {
         group += std::to_string(mArray[i]) + " ";
      }
   }
   mResults.push_back(group);
}



