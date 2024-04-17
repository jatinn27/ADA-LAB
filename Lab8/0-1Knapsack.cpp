#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &dp)
{
    for (auto i : dp)
    {
        for (auto j : i)
        {
            cout << j << "\t";
        }
        cout << endl
             << endl;
    }
}

int topDown(int capacity, vector<int> weight, vector<int> profit, int n, vector<vector<int>> &dp, int index)
{
    if (index >= n)
    {
        return 0;
    }

    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    int include = 0;

    if (weight[index] <= capacity)
        include = profit[index] + topDown(capacity - weight[index], weight, profit, n,dp, index + 1);

    int exclude = 0 + topDown(capacity, weight, profit, n,dp, index + 1);

    dp[index][capacity] = max(include, exclude);

    return dp[index][capacity];
}

int bottomUpApproach(int capacity, vector<int> weight, vector<int> profit, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= capacity; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (weight[i] <= j && (profit[i] + dp[i - 1][j - weight[i]] > dp[i - 1][j]))
            {
                dp[i][j] = profit[i] + dp[i - 1][j - weight[i]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{

    int capacity = 10;
    vector<int> profit = {10, 40, 30, 50};
    vector<int> wt = {5, 4, 6, 3};
    int n = 4;
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));

    int ans = bottomUpApproach(capacity, wt, profit, n);
    cout << "Max Profit bottom up: " << ans << endl;

    int index = 0;
    int res = topDown(capacity, wt, profit, n, dp, index);
    cout << "Max Profit Top down: " << res << endl;
    return 0;
}