#include <iostream>
#include <limits.h>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;

vector<int> randomnumbers(vector<int> arr, int n)
{
    int N = 100;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % N);
    }

    return arr;
}
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
    vector<int> arr;
    int max_val = INT_MIN;
    int min_val = INT_MAX;

    int input_size = 10000;
    do
    {
        arr = randomnumbers(arr, input_size);

        clock_t start, end;
        int x = 0;
        start = clock();

        for (int i = 0; i < 100; i++)
            MaxMin(arr, 0, arr.size()-1,max_val,min_val);

        end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;
        double average_time = time_taken / 100;

        cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
             << average_time << setprecision(5);
        cout << " sec " << endl;
        input_size = input_size + 10000;
    } while (input_size < 200000);

    return 0;
}

// Average Time taken by for input size 10000 is : 0.000080 sec 

// Average Time taken by for input size 20000 is : 0.00032 sec 

// Average Time taken by for input size 30000 is : 0.00074 sec 

// Average Time taken by for input size 40000 is : 0.00134 sec 

// Average Time taken by for input size 50000 is : 0.00183 sec 

// Average Time taken by for input size 60000 is : 0.00280 sec 

// Average Time taken by for input size 70000 is : 0.00346 sec 
// Average Time taken by for input size 120000 is : 0.00983 sec

// Average Time taken by for input size 130000 is : 0.01107 sec

// Average Time taken by for input size 140000 is : 0.01329 sec

// Average Time taken by for input size 150000 is : 0.01486 sec

// Average Time taken by for input size 160000 is : 0.01857 sec

// Average Time taken by for input size 170000 is : 0.02309 sec

// Average Time taken by for input size 180000 is : 0.02406 sec

// Average Time taken by for input size 190000 is : 0.02927 sec
