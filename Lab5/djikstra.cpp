#include <iostream>
#include "graphAdjMatrix.h"
#include <limits.h>
using namespace std;

void SSSP(int v, vector<vector<int>> &cost, vector<int> &dist, int n)
{
    vector<bool> s(n, false);
    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[v][i];
    }

    s[v] = true;
    dist[v] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minDist = INT_MAX;
        int u = -1;

        for (int i = 0; i < dist.size(); i++)
        {
            if (s[i] != true && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        s[u] = true;

        for (int i = 0; i < n; i++)
        {
            if (s[i] != true && dist[i] > cost[u][i] + dist[u] && u!=i)
            {
                dist[i] = cost[u][i] + dist[u];
            }
        }
    }
}
int main()
{
    int vertices;
    cout << "Enter the no. of vertices in the graph: ";
    cin >> vertices;
    int edges;
    cout << "Enter the no. of edges in the graph: ";
    cin >> edges;
    Graph g(vertices, edges, 0);

    g.makeMatrix();
    cout << "-----------------------------" << endl;
    g.displayMatrix();
    cout << "-----------------------------" << endl;

    pair<vector<vector<int>>, vector<vector<int>>> getInput = g.result();

    vector<vector<int>> cost = getInput.first;

    vector<int> dist(vertices, INT_MAX);

    int source_vertex = 0; 

    SSSP(source_vertex, cost, dist, vertices);

    cout << "Shortest distances from vertex " << source_vertex << " to all other vertices:" << endl;

    for (int i = 0; i < vertices; i++)
    {

        cout << "Distance to vertex " << i << ": " << dist[i] << endl;
    }
    return 0;
}