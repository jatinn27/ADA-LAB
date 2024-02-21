#include <iostream>
#include <vector>
#include<climits>
using namespace std;

void MaxMin(vector<int> &arr, int start, int end, int &max, int &min)
{
    if (start == end)
    {
        max = min = arr[start];
    }
    else if (start == end - 1)
    {
        if (arr[start] < arr[end])
        {
            max = arr[end];
            min = arr[start];
        }
        else
        {
            max = arr[start];
            min = arr[end];
        }
    }
    else
    {
        int mid = (start + end) / 2;
        int max1, min1;
        MaxMin(arr, start, mid, max, min);
        MaxMin(arr, mid + 1, end, max1, min1);
        if (max < max1)
            max = max1;
        if (min > min1)
            min = min1;
    }
}

int main()
{
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int n = arr.size();
    int max_val = INT_MIN;
    int min_val = INT_MAX;

    MaxMin(arr, 0, n - 1, max_val, min_val);

    cout << "Max value: " << max_val << endl;
    cout << "Min value: " << min_val << endl;

    return 0;
}
