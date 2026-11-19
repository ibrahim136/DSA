#ifndef _GRAPH_BFS_DFS
#define _GRAPH_BFS_DFS

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

class Graph
{
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int vertices);
    void addEdge(int u, int v);

    void PrintMatrix();

    void BFS_Print();
    void DFS_Print();
};

#endif