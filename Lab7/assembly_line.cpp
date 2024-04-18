#include <iostream>
#include <vector>
using namespace std;

int FASTESTWAY(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x) {
    int n = a[0].size();
    vector<int> f1(n);
    vector<int> f2(n);

    f1[0] = e[0] + a[0][0];
    f2[0] = e[1] + a[1][0];

    for (int j = 1; j < n; j++) {
        f1[j] = min(f1[j - 1] + a[0][j], f2[j - 1] + t[1][j - 1] + a[0][j]);
        f2[j] = min(f2[j - 1] + a[1][j], f1[j - 1] + t[0][j - 1] + a[1][j]);
    }

    return min(f1[n - 1] + x[0], f2[n - 1] + x[1]);
}

int main() {
    vector<vector<int>> a = {{1, 2, 3, 4}, {5, 6, 7, 8}};  
    vector<vector<int>> t = {{0, 4, 3, 5}, {0, 6, 2, 9}};  
    vector<int> e = {14, 13};
    vector<int> x = {14, 5}; 
    
    cout << FASTESTWAY(a, t, e, x);
    
    return 0;
}
