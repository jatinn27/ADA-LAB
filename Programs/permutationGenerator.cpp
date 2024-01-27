// done
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
    // to print the numbers generated
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

// Function for Selection sort
void permutation_generator(vector<int> &arr, vector<vector<int>> &ans, int index)
{
    // base case
    if (index >= arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int j = index; j < arr.size(); j++)
    {
        swap(arr[index], arr[j]);
        permutation_generator(arr, ans, index + 1);
        swap(arr[index], arr[j]);
    }
}

int main()
{
    vector<int> arr; // creating a dynamic array
    vector<vector<int>> ans;
    int input_size = 9;

    // generating random numbers
    arr = randomnumbers(arr, input_size);

    clock_t start, end;

    int index = 0;
    start = clock();

    for (int i = 0; i < 100; i++)
        permutation_generator(arr, ans, index);

    end = clock();

    // total time taken for running an algorithm 100 times for a specific input
    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    // avearge time time_taken/100
    double average_time = time_taken / 100;

    cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
         << average_time << setprecision(5);
    cout << " sec " << endl;

    return 0;
}