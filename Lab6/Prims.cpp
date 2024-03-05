#include <iostream>
#include "graphAdjMatrix.h"
#include <limits.h>
#include <iomanip>
using namespace std;

int findMinCostEdge(int vertices, vector<vector<int>> &cost, vector<int> &near)
{
    int minCost = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < vertices; i++)
    {
        if (near[i] != 0 && cost[i][near[i]] != 0 && cost[i][near[i]] < minCost)
        {
            minCost = cost[i][near[i]];
            minIndex = i;
        }
    }
    return minIndex;
}

pair<int, int> minCostedge(vector<vector<int>> &cost)
{
    int minCost = INT_MAX;
    int k, l;
    for (int i = 0; i < cost.size(); i++)
    {
        for (int j = 0; j < cost[i].size(); j++)
        {
            if (cost[i][j] != 0 && cost[i][j] < minCost)
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
            if (cost[i][l] != 0)
            {
                near[i] = l;
            }
            else
            {
                near[i] = k;
            }
        }
        else if (cost[i][l] > cost[i][k])
        {
            if (cost[i][k] != 0)
            {
                near[i] = k;
            }
            else
            {
                near[i] = l;
            }
        }
    }
    near[k] = near[l] = 0;

    for (int i = 1; i < t.size(); i++)
    {
        // let j be an index suzh that near[j] != 0 and cost[j,near[j]] is minimum;
        int j = findMinCostEdge(vertices, cost, near);
        t[i][0] = j;
        t[i][1] = near[j];
        minCost = minCost + cost[j][near[j]];
        near[j] = 0;

        for (int k = 0; k < vertices; k++)
        { // updatte near[]
            if (near[k] != 0 && cost[k][j] != 0 && cost[k][near[k]] > cost[k][j])
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