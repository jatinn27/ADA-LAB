#include <iostream>
#include <vector>
#include <set>
using namespace std;

void print(vector<int> x)
{
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

bool ispresent(pair<int, int> p, set<pair<int, int>> set)
{

    for (auto it = set.begin(); it != set.end(); it++)
    {
        if ((*it) == p)
        {
            return true;
        }
    }

    return false;
}

void print(set<pair<int, int>> &p)
{
    for (auto j : p)
    {
        cout << "(" << j.first << ", " << j.second << ")";
    }
}

void print(vector<set<pair<int, int>>> &s)
{
    int i = 0;
    for (auto set : s)
    {
        cout << "S^" << i << ": ";
        for (auto j : set)
        {
            cout << "(" << j.first << ", " << j.second << ")";
        }
        cout << endl;
        i++;
    }
}

set<pair<int, int>> merge_purge(set<pair<int, int>> &s1, set<pair<int, int>> &s2, int knapsackWt)
{

    set<pair<int, int>> s3;
    for (auto i : s1)
    {
        for (auto j : s2)
        {
            if (i.second <= knapsackWt && j.second <= knapsackWt)
            {
                s3.insert(i);
                s3.insert(j);
            }
        }
    }
    set<pair<int, int>> purged_s3;
    for (auto it = s3.begin(); it != s3.end(); it++)
    {
        bool isBetter = true;
        for (auto jt = s3.begin(); jt != s3.end(); jt++)
        {
            if ((it != jt) && (it->first < jt->first && it->second > jt->second))
            {
                isBetter = false;
                break;
            }
        }
        if (isBetter)
        {
            purged_s3.insert(*it);
        }
    }
    return purged_s3;
}

void knapsack(vector<int> &p, vector<int> &w, int n, int knpsck_wt, vector<int> &x)
{
    vector<set<pair<int, int>>> s(n + 1);
    s[0].insert({0, 0});

    for (int i = 0; i < n; i++)
    {
        set<pair<int, int>> temp;
        for (auto set : s[i])
        {
            temp.insert({set.first + p[i], set.second + w[i]});
        }

        s[i + 1] = merge_purge(s[i], temp, knpsck_wt);
    }

    // traceback
    int i = n;
    pair<int, int> store = (*s[i].rbegin());
    while (i > 0)
    {

        if (ispresent(store, s[i - 1]))
        {
            x[i - 1] = 0;
        }
        else
        {
            x[i - 1] = 1;
            store.first -= p[i - 1];
            store.second -= w[i - 1];
        }
        i--;
    }
}
int main()
{
    vector<int> w = {10,15,6,9};
    vector<int> p = {2,5,8,1};
    int n = 4;
    vector<int> x(n, -1);
    int knpsck_wt = 21;
    knapsack(p, w, n, knpsck_wt, x);

    print(x);
    return 0;
}