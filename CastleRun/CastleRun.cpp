#include "CastleRun.h"

#include <algorithm>

// find path back to the original by depth first search

// do not visit if edge is used

class Door
{
public:
    Door() : mUsed(false)
    {}
    
    
private:
    bool mUsed;
    
};

class Room
{
public:
    Room() : mVisited(false)
    {}
    
    
private:
    bool mVisited;
    vector<Door*> mDoors;
    
};
