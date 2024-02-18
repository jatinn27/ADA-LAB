#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;

vector<int> randomnumbers(vector<int> arr, int n)
{
    int N = 100; // This function will generate random numbers for n=50 it will generate 50 numbers
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % N);
    }

    return arr;
}

int horner(vector<int> &arr, int n, int x)
{
    int result = arr[0];

    for (int i = 1; i < n; i++)
        result = result * x + arr[i];

    return result;
}

int main()
{
    vector<int> arr; // creating a dynamic array

    vector<int> ans;
    int input_size = 10000;

    do
    {
    
        // generating random numbers
        arr = randomnumbers(arr, input_size);

        // to calculate time if an algorithm runs 100 times for a specific input
        clock_t start, end;

        start = clock();

        for (int i = 0; i < 100; i++)
            ans.push_back(horner(arr, input_size, input_size - 1));

        end = clock();

        // total time taken for running an algorithm 100 times for a specific input
        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        // avearge time time_taken/100
        double average_time = time_taken / 100;

        cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
             << average_time << setprecision(5);
        cout << " sec " << endl;
        input_size = input_size + 1000;
    } while (input_size < 100000);
    return 0;
}
