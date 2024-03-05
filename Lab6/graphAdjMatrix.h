#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    vector<vector<int>> adjMatrix;
    vector<vector<int>> edgeList; // Added initialization
    bool direction;
    int edges;
    int vertices;

public:
    Graph(int vertices, int edges, bool direction)
    {
        this->vertices = vertices;
        this->edges = edges;
        this->direction = direction;

        adjMatrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));
    }

    pair<vector<vector<int>>, vector<vector<int>>> result()
    {
        return {adjMatrix, edgeList};
    }

    void displayEdgeList()
    {
        cout << "Edge List:" << endl;
        for (int i = 0; i < edgeList.size(); i++)
        {
            cout << "Edge " << i + 1 << ": " << edgeList[i][0] << " -> " << edgeList[i][1] << endl;
        }
    }

    void displayMatrix()
    {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addEdge(int u, int v, int weight)
    {
        adjMatrix[u][v] = weight;
        if (!direction)
        {
            adjMatrix[v][u] = weight;
        }
        edgeList.push_back({u, v});
        if (!direction)
        {
            edgeList.push_back({v, u});
        }
    }

    void makeMatrix()
    {
        for (int i = 0; i < edges; i++)
        {
            int u, v, wt;
            cout << "Edge " << i + 1 << ": " << endl;
            cout << "Initial vertex: ";
            cin >> u;
            cout << "Final vertex: ";
            cin >> v;
            cout << "Enter weight between " << u << " and " << v << ": ";
            cin >> wt;

            if (u >= 0 && u < vertices && v >= 0 && v < vertices)
            {
                if (u != v)
                {
                    addEdge(u, v, wt);
                }
            }
            else
            {
                cout << "Invalid vertices. Enter vertices between 0 and " << vertices - 1 << endl;
                i--;
            }
        }
    }
};

