#include <iostream>
#include <vector>
#include <iomanip> // setprecision()
#include <cstdlib> // clock_t
using namespace std;

void print(vector<int> arr)
{
    // to print the numbers generated
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

vector<int> randomnumbers(vector<int> arr, int n)
{
    int N = 100;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % N);
    }

    return arr;
}
#include <vector>
#include <algorithm>

vector<int> exactPositionPivot(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int pivotIndex = low;

    while (low < high)
    {
        while (arr[low] <= arr[pivotIndex])
        {
            low++;
        }

        while (arr[high] > arr[pivotIndex])
        {
            high--;
        }

        if (low < high)
        {
            swap(arr[high], arr[low]);
        }
    }

    swap(arr[pivotIndex], arr[high]);

    return arr;
}

int main()
{
    vector<int> arr;

    int input_size;

    for (int input_size = 1000; input_size <= 1000000; input_size = input_size + 20000)
    {
        arr = randomnumbers(arr, input_size);

        clock_t start, end;

        start = clock();

        for (int i = 0; i < 100; i++)
            exactPositionPivot(arr);

        end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        double average_time = time_taken / 100;

        cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
    }
    return 0;
}

// Average Time taken by for input size 1000 is : 0.000000 sec 

// Average Time taken by for input size 21000 is : 0.00600 sec 

// Average Time taken by for input size 41000 is : 0.01600 sec 

// Average Time taken by for input size 61000 is : 0.06100 sec 

// Average Time taken by for input size 81000 is : 0.09000 sec 

// Average Time taken by for input size 101000 is : 0.12800 sec 

// Average Time taken by for input size 121000 is : 0.18800 sec 

// Average Time taken by for input size 141000 is : 0.32100 sec 

// Average Time taken by for input size 161000 is : 0.33300 sec 

// Average Time taken by for input size 181000 is : 0.41500 sec 

// Average Time taken by for input size 201000 is : 0.41500 sec

// Average Time taken by for input size 221000 is : 0.55900 sec

// Average Time taken by for input size 241000 is : 0.64200 sec

// Average Time taken by for input size 261000 is : 0.80100 sec

// Average Time taken by for input size 281000 is : 0.82900 sec

// Average Time taken by for input size 301000 is : 0.98300 sec

// Average Time taken by for input size 321000 is : 1.05400 sec

// Average Time taken by for input size 341000 is : 1.18800 sec

// Average Time taken by for input size 361000 is : 1.37400 sec

// Average Time taken by for input size 381000 is : 1.48700 sec

// Average Time taken by for input size 401000 is : 1.53400 sec

// Average Time taken by for input size 421000 is : 1.71900 sec