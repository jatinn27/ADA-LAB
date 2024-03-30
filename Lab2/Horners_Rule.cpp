#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Generate n random numbers and append them to arr
void randomnumbers(vector<int> &arr, int n)
{
    int N = 100;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % N);
    }
}

int hornerRule(const vector<int> &arr, int m, int n, int x)
{
    if (m == n)
    {
        return arr[m];
    }
    else
    {
        return arr[n] + x * hornerRule(arr, m, n + 1, x);
    }
}

int main()
{

    for (int input_size = 100; input_size <= 10000; input_size = input_size + 100)
    {
        vector<int> arr;
        randomnumbers(arr, input_size);

        clock_t start, end;
        
        int result = 0;
        start = clock();

        for (int i = 0; i < 100; i++)
        {
            result = hornerRule(arr, arr.size() - 1, 0, 2);
        }

        end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;
        double average_time = time_taken / 100;

        cout << "Average Time taken for input size " << input_size << " is: " << fixed
             << average_time << setprecision(5) << " sec" << endl;
    }

    return 0;
}
