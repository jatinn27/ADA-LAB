#include <iostream>
#include <vector>
#include <iomanip> // setprecision()
#include <cstdlib> // clock_t
using namespace std;
vector<int> sortedNumbers(vector<int> arr, int input_size)
{
    for (int i = 1; i <= input_size; i++)
    {
        arr.push_back(i);
    }

    return arr;
}
void print(vector<int> arr)
{
    // to print the numbers generated
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
int binarySearch(vector<int> &arr, int start, int end, int key)
{
    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[mid] > key)
    {
        binarySearch(arr, start, mid - 1, key);
    }
    else
    {
        binarySearch(arr, mid + 1, end, key);
    }
}

int main()
{
    vector<int> arr;
    int input_size;
    int key;

    for (int input_size = 10000; input_size <= 100000000; input_size = input_size * 2)
    {
        key = input_size/2;
        arr = sortedNumbers(arr, input_size);

        int s = 0;
        int e = arr.size() - 1;
        clock_t start, end;

        start = clock();

        for (int i = 0; i < 100; i++)
            binarySearch(arr,s,e,key);

        end = clock();

        // total time taken for running an algorithm 100 times for a specific input
        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        // avearge time time_taken/100
        double average_time = time_taken / 100;

        cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
             << average_time << setprecision(5);
        cout << " sec " << endl;
        key = key + 50;
    }

    return 0;
}