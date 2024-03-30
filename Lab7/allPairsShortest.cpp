#include <iostream>
#include "graphAdjMatrix.h"
#include <limits.h>
using namespace std;

void allPaths(vector<vector<int>> &cost,vector<vector<int>> &A,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]  = cost[i][j];
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                A[i][j] = min(A[i][j],A[i][k] + A[k][j]);
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
    Graph g(vertices, edges, 1);

    g.makeMatrix();
    cout << "-----------------------------" << endl;
    g.displayMatrix();
    cout << "-----------------------------" << endl;
    pair<vector<vector<int>>, vector<vector<int>>> getInput = g.result();
    vector<vector<int>> A(vertices, vector<int>(vertices, -1));

    allPaths(getInput.first,A,vertices);

    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}