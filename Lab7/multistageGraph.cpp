#include <iostream>
#include <vector>

#define MAX_NODES 10
#define INFINITY 1000

using namespace std;

vector<vector<int>> graph(MAX_NODES, vector<int>(MAX_NODES, 0));
vector<int> path(MAX_NODES, -1);
int numNodes;

void initializeGraph()
{
    cout << "\nEnter the number of nodes: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++)
    {
        graph[i][i] = 0;
        for (int j = i + 1; j < numNodes; j++)
        {
            cout << "Enter the weight of edge '" << char('A' + i) << "' to '" << char('A' + j) << "': ";
            cin >> graph[i][j];
            graph[j][i] = 0;
        }
    }
}

void displayGraph()
{
    cout << "\nThe Path adjacent matrix\n";
    for (int i = 0; i < numNodes; i++)
    {
        cout << "\n";
        for (int j = 0; j < numNodes; j++)
            cout << "\t" << graph[i][j];
    }
}

int findShortest(int src, int dst)
{
    if (src == dst)
        return 0;
    else
    {
        int ret = -1;
        int minDist = INFINITY;
        int tmpDst;
        for (int i = 0; i < numNodes; i++)
        {
            if (graph[src][i] != 0)
            {
                ret = 0;
                tmpDst = graph[src][i] + findShortest(i, dst);
                if (minDist > tmpDst)
                {
                    minDist = tmpDst;
                    path[src] = i;
                }
            }
        }
        if (ret == -1)
            return INFINITY;
        else
            return minDist;
    }
}

void findAndDisplayShortestPath()
{
    char src, dst;
    int srcIndex, dstIndex;
    cout << "\nEnter the source and destination node: ";
    cin >> src >> dst;
    srcIndex = src - 'A';
    dstIndex = dst - 'A';
    int dist = findShortest(srcIndex, dstIndex);
    if (dist >= INFINITY)
        cout << "\nThe shortest distance between '" << src << "' and '" << dst << "' can't be computed";
    else
    {
        cout << "\nThe shortest distance between '" << src << "' and '" << dst << "': " << dist;
        cout << "\nThe shortest path: " << src;
        while (srcIndex != dstIndex)
        {
            cout << " " << char('A' + path[srcIndex]);
            srcIndex = path[srcIndex];
        }
    }
}

int main()
{
    initializeGraph();
    displayGraph();
    findAndDisplayShortestPath();
    return 0;
}
