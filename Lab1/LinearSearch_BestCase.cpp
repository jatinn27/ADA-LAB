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

int LinearSearch(vector<int> &arr, int key, int index)
{
    if (index >= arr.size())
    {
        return -1;
    }
    if (arr[index] == key)
    {
        return index;
    }
    else
    {
        return LinearSearch(arr, key, index + 1);
    }
}

int main()
{
    vector<int> arr;
    int input_size;
    int key;

    for (int input_size = 1000; input_size <= 100000; input_size = input_size + 100)
    {
        key = 1;
        arr = sortedNumbers(arr, input_size);

        int index = 0 ;
        clock_t start, end;

        start = clock();

        for (int i = 0; i < 100; i++)
            LinearSearch(arr, key,index);

        end = clock();

        // total time taken for running an algorithm 100 times for a specific input
        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        // avearge time time_taken/100
        double average_time = time_taken / 100;

        cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
             << average_time << setprecision(5);
        cout << " sec " << endl;
    }

    return 0;
}