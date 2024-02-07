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

