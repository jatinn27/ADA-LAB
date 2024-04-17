#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void Snapshot(const vector<vector<int>>& s, int i, int j) {
    if (i == j)
        cout << "A" << i - 1;
    else {
        cout << "(";
        Snapshot(s, i, s[i][j]);
        Snapshot(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void MatrixChainOrder(vector<int>& p) {
    int n = p.size();
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int l = 2; l < n; l++)
        for (int i = 1, j = i + l - 1; i < n - l + 1; i++, j = i + l - 1) {
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }

    cout << m[1][n - 1] << endl;
    Snapshot(s, 1, n - 1);
    cout << endl;
}

int main() {
    vector<int> Sequence = {30, 35, 15, 5, 10, 20, 25};

    MatrixChainOrder(Sequence);
    return 0;
}
