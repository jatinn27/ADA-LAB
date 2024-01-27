#include <iostream>
#include <time.h>
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

int Sum(vector<int> &arr, int i, int size)
{

    if (size == 1)
    {
        return arr[i];
    }
    else
    {
        return arr[i] + Sum(arr, i + 1, size - 1);
    }
}

int main()
{
    vector<int> arr;

    int input_size = 10000;
    do
    {
        arr = randomnumbers(arr, input_size);

        clock_t start, end;
        int x = 0;
        start = clock();

        for (int i = 0; i < 100; i++)
            Sum(arr, x, arr.size());

        end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;
        double average_time = time_taken / 100;

        cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        input_size = input_size + 1000;
    } while (input_size < 20000);
    return 0;
}