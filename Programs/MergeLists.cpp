#include <iostream>
#include <vector>
#include <iomanip> // setprecision()
#include <cstdlib> // clock_t
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

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

vector<int> Mergelists(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> arr3;
    int start1 = 0;
    int start2 = 0;

    while (start1 < arr1.size() && start2 < arr2.size())
    {
        if (arr1[start1] < arr2[start2])
        {
            arr3.push_back(arr1[start1]);
            start1++;
        }
        else
        {
            arr3.push_back(arr2[start2]);
            start2++;
        }
    }

    while (start1 < arr1.size())
    {
        arr3.push_back(arr1[start1]);
        start1++;
    }

    while (start2 < arr2.size())
    {
        arr3.push_back(arr2[start2]);
        start2++;
    }

    return arr3;
}

int main()
{
    vector<int> merged;

    int input_size;

    for (int input_size = 1000; input_size <= 1000000; input_size = input_size + 20000)
    {
        merged = randomnumbers(merged, input_size);

        vector<int> arr1;
        for (int i = 0; i < input_size / 2; i++)
        {
            arr1.push_back(merged[i]);
        }
        vector<int> arr2;
        for (int i = input_size / 2; i < input_size; i++)
        {
            arr2.push_back(merged[i]);
        }

        clock_t start, end;

        start = clock();

        for (int i = 0; i < 100; i++)
            merged = Mergelists(arr1, arr2);

        end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        double average_time = time_taken / 100;

        cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
    }
    return 0;
}
