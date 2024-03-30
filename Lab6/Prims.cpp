#include <iostream>
#include "graphAdjMatrix.h"
#include <limits.h>
#include <iomanip>
using namespace std;

// near[i] == -2 means visited to handle vertex 0

int findMinCostVertex(int vertices, vector<vector<int>> &cost, vector<int> &near)
{
    int minCost = INT_MAX;
    int minVertex = -1;
    for (int i = 0; i < vertices; i++)
    {
        if (near[i] != -2 && cost[i][near[i]] < minCost && i != near[i])
        {
            minCost = cost[i][near[i]];
            minVertex = i;
        }
    }
    return minVertex;
}

pair<int, int> minCostedge(vector<vector<int>> &cost)
{
    int minCost = INT_MAX;
    int k, l;
    for (int i = 0; i < cost.size(); i++)
    {
        for (int j = 0; j < cost[i].size(); j++)
        {
            if (cost[i][j] < minCost && i != j)
            {
                minCost = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    return {k, l};
}
int primAlgorithm(vector<vector<int>> &cost, int vertices, vector<vector<int>> &t)
{
    // let (k,l) be an edge of minimum cost in E;
    pair<int, int> minEdge = minCostedge(cost);
    int k = minEdge.first;
    int l = minEdge.second;
    int minCost = 0;
    minCost = cost[k][l];
    t[0][0] = k;
    t[0][1] = l;

    vector<int> near(vertices, -1);

    for (int i = 0; i < vertices; i++)
    {
        if (cost[i][l] < cost[i][k])
        {
            near[i] = l;
        }
        else
        {
            near[i] = k;
        }
    }
    near[k] = near[l] = -2;

    for (int i = 1; i < t.size(); i++)
    {
        // let j be an index/vertex such that near[j] != 0 and cost[j,near[j]] is minimum;
        int j = findMinCostVertex(vertices, cost, near);
        t[i][0] = j;
        t[i][1] = near[j];
        minCost = minCost + cost[j][near[j]];
        near[j] = -2;

        for (int k = 0; k < vertices; k++)
        { // update near[]

            if (near[k] != -2 && cost[k][near[k]] > cost[k][j] && k!=near[k] && k!=j)
            {
                near[k] = j;
            }
        }
    }

    return minCost;
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
    vector<vector<int>> t(vertices - 1, vector<int>(2, -1));
    int minCost = primAlgorithm(getInput.first, vertices, t);

    cout << "Min cost of spanning tree is " << minCost << endl;

    cout << "-----------------------------" << endl;
    cout << "Edges in the spanning tree: " << endl;
    for (auto i : t)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}