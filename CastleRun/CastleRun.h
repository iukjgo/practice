#ifndef Castle_Run_h
#define Castle_Run_h

#include <iostream>
#include <vector>

class Graph
{
public:
    Graph(int v) : mAdj(v), mVertices(v) {};
    
    int getVerticesCount() { return mVertices; };
    void addEdge(int u, int v);
    std::vector<int>* getAdjList(int u);
private:
    std::vector<std::vector<int>> mAdj;
    int mVertices;
    int mEdges;
};

// find if Euler Circuit exists
class CastleRun
{
public:
    static bool solveDirected(Graph& g);
    static bool solveUndirected(Graph& g);
};

#endif /* Castle_Run_h */
