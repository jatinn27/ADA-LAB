#include <iostream>
#include <vector>
#include <iomanip> // setprecision()
#include <cstdlib> // clock_t
using namespace std;

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int partition(vector<int> &arr, int start, int end)
{
    int pivotIndex = start;

    while (start < end)
    {
        while (arr[start] <= arr[pivotIndex])
        {
            start++;
        }

        while (arr[end] > arr[pivotIndex])
        {
            end--;
        }

        if (start < end)
        {
            swap(arr[end], arr[start]);
        }
    }

    swap(arr[pivotIndex], arr[end]);

    return pivotIndex;
}

int kthSmallestElement(vector<int> &arr, int k)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;

    while (start <= end)
    {
        int p = partition(arr, start, end);

        if (p == k - 1)
        {
            ans = p;
            break;
        }
        else if (p < k - 1)
        {
            start = p + 1;
        }
        else
        {
            end = p - 1;
        }
    }

    return ans;
}

void selectionSort(vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int small = kthSmallestElement(arr, i + 1); 
        swap(arr[i], arr[small]);
    }
}
int main()
{
    vector<int> arr = {9,2,4,1,5,6,3};

    print(arr);

    selectionSort(arr);
    print(arr);

    return 0;
}