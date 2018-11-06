//
//  KnightWalk.cpp
//
//  Created by Abraham Kim on 2018/11/6.
//

#include "KnightWalk.h"


void
KnightWalk::setBoardToSolve(int x, int y)
{
    mX = x;
    mY = y;
    mBoard = std::vector<std::vector<bool>>(mY, std::vector<bool>(mX, false));
}

int
KnightWalk::solve(int srcX, int srcY, int destX, int destY)
{
    // error check
    if (!isWithinBoard(destX, destY))
        return -1;
    if (!isWithinBoard(srcX, srcY))
        return -1;
    
    std::pair<int,int> destination(destX, destY);
    
    std::queue<std::pair<int,int>> positions;
    
    
    int depth = 0;
    int curDepthCounter = 1;
    int nextDepthCounter = 0;
    positions.push(std::make_pair(srcX, srcY));
    
    while (!positions.empty()) {
        
        std::pair<int,int> curPos = positions.front();
        positions.pop();
        mBoard[curPos.second][curPos.first] = true;
        curDepthCounter--;
        
        if (curPos == destination)
            return depth;
        
        nextDepthCounter += addNextMovablePositions(positions, curPos);
        
        if (curDepthCounter == 0) {
            depth++;
            curDepthCounter = nextDepthCounter;
            nextDepthCounter = 0;
        }
    }
    
    return -1;
}

bool
KnightWalk::isWithinBoard(const int posX, const int posY)
{
    if (posX < 0 )
        return false;
    if (posX >= mX)
        return false;
    if (posY < 0)
        return false;
    if (posY >= mY)
        return false;
    
    return true;
}

bool
KnightWalk::isWithinBoard(const std::pair<int,int>& pos)
{
    return isWithinBoard(pos.first, pos.second);
}

bool
KnightWalk::isVisited(const std::pair<int,int>& pos)
{
    return mBoard[pos.second][pos.first];
}

int
KnightWalk::addNextMovablePositions(std::queue<std::pair<int,int>>& positions, const std::pair<int,int>& curPos)
{
    int curX = curPos.first;
    int curY = curPos.second;
    // max 8 possible positions
    std::pair<int,int> pos1(curX+2, curY+1);
    std::pair<int,int> pos2(curX+2, curY-1);
    
    std::pair<int,int> pos3(curX+1, curY-2);
    std::pair<int,int> pos4(curX-1, curY-2);
    
    std::pair<int,int> pos5(curX-2, curY-1);
    std::pair<int,int> pos6(curX-2, curY+1);
    
    std::pair<int,int> pos7(curX-1, curY+2);
    std::pair<int,int> pos8(curX+1, curY+2);
    
    int count = 8;
    
    if (isWithinBoard(pos1) && !isVisited(pos1))
        positions.push(pos1);
    else count--;
        
    if (isWithinBoard(pos2) && !isVisited(pos2))
        positions.push(pos2);
    else count--;
    
    if (isWithinBoard(pos3) && !isVisited(pos3))
        positions.push(pos3);
    else count--;
    
    if (isWithinBoard(pos4) && !isVisited(pos4))
        positions.push(pos4);
    else count--;
    
    if (isWithinBoard(pos5) && !isVisited(pos5))
        positions.push(pos5);
    else count--;
    
    if (isWithinBoard(pos6) && !isVisited(pos6))
        positions.push(pos6);
    else count--;
    
    if (isWithinBoard(pos7) && !isVisited(pos7))
        positions.push(pos7);
    else count--;
    
    if (isWithinBoard(pos8) && !isVisited(pos8))
        positions.push(pos8);
    else count--;
    
    return count;
}
