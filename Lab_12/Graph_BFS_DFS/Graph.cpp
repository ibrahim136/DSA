#include "Graph.h"

Graph::Graph(int vertices) : numVertices(vertices)
    {
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }


void Graph::addEdge(int u, int v)
    {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices)
        {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
    }

void Graph::PrintMatrix()
{
    std::cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::BFS_Print()
{
    std::vector<int> visited;
    std::queue<int> q;
    visited.push_back(0);
    q.push(0);
    int temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        std::cout << temp + 1 << " ";
        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[temp][i] == 1 && std::find(visited.begin(), visited.end(), i) == visited.end())
            {
                q.push(i);
                visited.push_back(i);
            }
        }
    }
}


void Graph::DFS_Print()
{
    std::vector<int> visited;
    std::stack<int> s;
    visited.push_back(0);
    s.push(0);
    int temp;
    std::cout << 0 + 1 << " ";
    while (!s.empty())
    {
        temp = s.top();
        bool found_a_path = false;
        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[temp][i] == 1 && std::find(visited.begin(), visited.end(), i) == visited.end())
            {
                s.push(i);
                visited.push_back(i);
                std::cout << i + 1 << " ";
                found_a_path = true;
                break;
            }
        }
        if (!found_a_path)
        {
            s.pop();
        }
    }
}