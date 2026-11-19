#include "Graph_BFS_DFS/Graph.h"

int main()
{
    int vertices, edges;
    std::cout << "Enter number of vertices and edges: ";
    std::cin >> vertices >> edges;

    Graph g(vertices);

    std::cout << "Enter " << edges << " edges (u v) using 1-based indexing:\n";
    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        g.addEdge(u-1, v-1);
    }

    g.PrintMatrix();

    std::cout << "\n\n\nPrint 1 Based BSF\n";
    g.BFS_Print();
    
    
    std::cout << "\n\n\nPrint 1 Based DSF\n";
    g.DFS_Print();

    return 0;
}