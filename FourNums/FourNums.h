﻿//
//  FourNum.h
//
//  Created by Abraham Kim on 2018/11/05
//
/*
https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers/0
Find all four sum numbers
Submissions: 14947   Accuracy: 14.64%   Difficulty: Medium

Given an array A of size N, find all combination of four elements in the array whose sum is equal to a given value K. For example, if the given array is {10, 2, 3, 4, 5, 9, 7, 8} and K = 23, one of the quadruple is “3 5 7 8” (3 + 5 + 7 + 8 = 23).

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains two integers N and K. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line print all the quadruples present in the array separated by space which sums up to value of K. Each quadruple is unique which are separated by a delimeter "$" and are in increasing order.

Constraints:
1<=T<=100
1<=N<=100
-1000<=K<=1000
-100<=A[]<=100

Example:
Input:
2
5 3
0 0 2 1 1
7 23
10 2 3 4 5 7 8
Output:
0 0 1 2 $
2 3 8 10 $2 4 7 10 $3 5 7 8 $
*/
#ifndef FourNums_FourNums_h
#define FourNums_FourNums_h

#include <iostream>
#include <vector>

class FourNums
{
public:
   FourNums() : mNumOfElements(4) {};
   void setArrayToSolve(std::vector<int>& array);
   std::vector<std::string> solve(int goalValue) { return solveGeneric(goalValue);};
   std::vector<std::string> solveGeneric(int goalValue);


private:
   const int mNumOfElements;
   void registerGroup();
   bool findGroups(int goalValue, int numOfElements, int pos);
   std::vector<int> mArray;
   std::vector<bool> mInclude;
   std::vector<std::string> mResults;
};

#endif /* FourNums_FourNums_h */