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

int partition(vector<int> &arr,int start,int end){
    int pivotIndex = start;

   while (start < end)
    {
        while (arr[start] <= arr[pivotIndex])
        {
            start++;
        }

        while (arr[end] > arr[pivotIndex])
        {
            end--;
        }

        if (start < end)
        {
            swap(arr[end], arr[start]);
        }
    }

    swap(arr[pivotIndex], arr[end]);

    return pivotIndex;
}

int kthSmallestElement(vector<int> &arr, int k)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;

    while (start <= end)
    {
        int p = partition(arr, start, end);

        if (p == k - 1)
        {
            ans = arr[p];
            break;
        }
        else if (p < k - 1)
        {
            start = p + 1;
        }
        else
        {
            end = p - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr; // creating a dynamic array

    for(int input_size=100;input_size<10000;input_size = input_size +100){


    // generating random numbers
    arr = randomnumbers(arr, input_size);

    // to calculate time if an algorithm runs 100 times for a specific input
    clock_t start, end;

    start = clock();

    for (int i = 0; i < 100; i++)
        kthSmallestElement(arr,input_size/2);

    end = clock();

    // total time taken for running an algorithm 100 times for a specific input
    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    // avearge time time_taken/100
    double average_time = time_taken / 100;

    cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    }

    return 0;
}


// Average Time taken by for input size 100 is : 0.001000 sec 

// Average Time taken by for input size 200 is : 0.00400 sec 

// Average Time taken by for input size 300 is : 0.01700 sec 

// Average Time taken by for input size 400 is : 0.05100 sec 

// Average Time taken by for input size 500 is : 0.09700 sec 

// Average Time taken by for input size 600 is : 0.15100 sec 

// Average Time taken by for input size 700 is : 0.25100 sec 

// Average Time taken by for input size 800 is : 0.34400 sec 

// Average Time taken by for input size 900 is : 0.53600 sec 

// Average Time taken by for input size 1000 is : 0.71700 sec 
