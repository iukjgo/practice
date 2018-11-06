//
//  KnightWalk.h
//
//  Created by Abraham Kim on 2018/11/6.
//
/*
 Knight Walk Submissions: 8491   Accuracy: 28.09%   Difficulty: Medium
 
 Given a chess board of order NxM and source points (s1,s2) and destination points (d1,d2), Your task to find min number of moves required by the Knight to go to the destination cell.
 
 Input:
 The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of each test case contains two space separated integers N and M. Then in the next line are four space separated values s1, s2 and d1, d2.
 
 Output:
 For each test case in a new line print the min no of moves required by the knight to go to the destination from the source. If no such move is possible print -1.
 
 Constraints:
 1<=T<=100
 1<=N,M<=25
 
 Example:
 Input:
 2
 4 7
 2 6 2 4
 7 13
 2 8 3 4
 Output:
 2
 3
 */


#ifndef KnightWalk_h
#define KnightWalk_h


#include <queue>
#include <vector>
#include <utility>


class KnightWalk
{
public:
    void setBoardToSolve(int x, int y);
    int solve(int srcX, int srcY, int destX, int destY);
    
    
private:
    bool isWithinBoard(const int posX, const int posY);
    bool isWithinBoard(const std::pair<int,int>& pos);
    bool isVisited(const std::pair<int,int>& pos);
    int addNextMovablePositions(std::queue<std::pair<int,int>>& positions, const std::pair<int,int>& curPos);
private:
    std::vector<std::vector<bool>> mBoard;
    int mX;
    int mY;
};

#endif /* KnightWalk_h */
