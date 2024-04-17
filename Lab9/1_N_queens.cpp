#include <iostream>
#include <vector>
using namespace std;

// bounding function
bool place(int k, int i, vector<int> &x)
{
    for (int j = 1; j < k ; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return false;
        }
    }

    return true;
}

void n_queens(int k, int n, vector<int> &x)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i, x))
        {
            x[k] = i;
            if (k == n)
            {
                for (int i = 1; i < x.size(); i++)
                {
                    cout << x[i]<<" ";
                }
                cout << endl;
            }
            else
            {
                n_queens(k + 1, n, x);
            }
        }
    }
}

int main()
{
    int no_of_queens;
    cout << "Enter the number of queens: ";
    cin >> no_of_queens;
    vector<int> x(no_of_queens + 1,-1);
    n_queens(1, no_of_queens, x);
    return 0;
}