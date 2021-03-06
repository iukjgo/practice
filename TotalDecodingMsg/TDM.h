//
//  TDM.h
//
//  Created by Abraham Kim on 2018/11/06.
//
/*
https://practice.geeksforgeeks.org/problems/total-decoding-messages/0/?ref=self
 Total Decoding Messages Submissions: 25249   Accuracy: 21.49%   Difficulty: Medium
                  
A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded.
Note: An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and If there are leading 0’s, extra trailing 0’s and two or more consecutive 0’s then it is an invalid string.

Example :
Given encoded message "123",  it could be decoded as "ABC" (1 2 3) or "LC" (12 3) or "AW"(1 23).
So total ways are 3.

Input:
First line contains the test cases T.  1<=T<=1000
Each test case have two lines
First is length of string N.  1<=N<=40
Second line is string S of digits from '0' to '9' of N length.

Example:
Input:
2
3
123
4
2563
Output:
3
2
 */


#ifndef TDM_h
#define TDM_h

#include <unordered_map>
#include <queue>
#include <vector>
#include <utility>


class TDM
{
public:
   int solve();
   void setMessageToSolve(std::string s);

private:
   int getDecodePossibilityCount(int strtPos);
   int getDecodePossibilityCountIterative();

private:
    bool mValid;
    std::string mStr;
    std::unordered_map<int,int> mCountCache;
};

#endif /* TDM_h */
