#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<int> findMinIndex(vector<vector<int>> &matrix)
{
    vector<int> minIndex = {-1, -1};

    int minVal = matrix[0][0];

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] < minVal)
            {
                minVal = matrix[i][j];
                minIndex[0] = i;
                minIndex[1] = j;
            }
        }
    }

    return minIndex;
}

int findindex( int minCost,int n, vector<int> &near, vector<vector<int>> &cost)
{
    int j = -1;

    for (int i = 0; i < n; i++)
    {
        if (near[i] != 0 && cost[i][near[i]] < minCost)
        {
            j = i;
        }
    }

    return j;
}

void prims(vector<vector<int>> &edges, vector<vector<int>> &cost, int n, vector<vector<int>> &t)
{
    vector<int> minEdge = findMinIndex(cost);
    int k = minEdge[0];
    int l = minEdge[1];
    vector<int> near(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (cost[i][k] < cost[i][l])
        {
            near[i] = k;
        }
        else
        {
            near[i] = l;
        }
    }

    t[0][0] = k;
    t[0][1] = l;

    near[k] = near[l] = 0;

    for(int i=0;i<n;i++){
        cout<<near[i]<<" ";
    }

    // int minCost = cost[k][l];

    // for (int i = 1; i < n - 1; i++)
    // {
    //     int j = findindex(minCost, n, near, cost);
    //     t[i][0] = j;
    //     t[i][1] = near[j];

    //     minCost += cost[j][near[j]];
    //     near[j] = 0;

    //     for (int k = 1; k < n; k++)
    //     {
    //         if ((near[k] != 0) && (cost[k][near[k]] > cost[k][j]))
    //         {
    //             near[k] = j;
    //         }
    //     }
    // }

    // return minCost;

}

int main()
{
    int n = 6;
    int infinity = numeric_limits<int>::max();

    vector<vector<int>> cost(n, vector<int>(n, infinity));

    vector<vector<int>> t(n - 1, vector<int>(2));


    cost[0][4] = 9;
    cost[4][0] = 9;
    cost[0][1] = 3;
    cost[1][0] = 3;
    cost[0][5] = 4;
    cost[5][0] = 4;
    cost[5][2] = 7;
    cost[2][5] = 7;
    cost[1][5] = 2;
    cost[5][1] = 2;
    cost[1][4] = 3;
    cost[4][1] = 3;
    cost[4][3] = 6;
    cost[3][4] = 6;
    cost[5][3] = 8;
    cost[3][5] = 8;
    cost[5][4] = 5;
    cost[4][5] = 5;
    cost[0][0] = 0;
    cost[1][1] = 0;
    cost[2][2] = 0;
    cost[3][3] = 0;
    cost[4][4] = 0;
    cost[5][5] = 0;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }

    // int minCost = prims(edges, cost, n, t);

    // cout << "Min cost is " << minCost;

    return 0;
}
