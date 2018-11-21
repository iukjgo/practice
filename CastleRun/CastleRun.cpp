#include "CastleRun.h"

#include <algorithm>

void
Graph::addEdge(int u, int v)
{
    mAdj[u].push_back(v);
}

std::vector<int>*
Graph::getAdjList(int u)
{
    return &mAdj[u];
}


bool
CastleRun::solveDirected(Graph& g)
{
    std::vector<int> inDegree (g.getVerticesCount(), 0);
    std::vector<int> outDegree(g.getVerticesCount(), 0);
    
    for (int u=0; u<g.getVerticesCount(); u++) {
        std::vector<int>* adj = g.getAdjList(u);
        
        outDegree[u] = (int)adj->size();
        
        for (int i=0; i<adj->size(); i++) {
            int v = adj->at(i);
            inDegree[v]++;
        }
    }
    
    for (int u=0; u<g.getVerticesCount(); u++) {
        if (inDegree[u] != outDegree[u])
            return false;
    }
    
    return true;
}



bool
CastleRun::solveUndirected(Graph& g)
{
    if (g.getVerticesCount() == 1)
        return true;
    
    int oddDegree = 0;
    
    for (int u=0; u<g.getVerticesCount(); u++) {
        if ((int)g.getAdjList(u)->size() == 0)
            return false;
        if ((int)g.getAdjList(u)->size() % 2 == 1)
            return false;
    }
    
    return true;
}
