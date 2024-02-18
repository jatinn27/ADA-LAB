#include <iostream>
#include <vector>
#include <iomanip> // setprecision()
#include <cstdlib> // clock_t
using namespace std;

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> randomnumbers(vector<int> arr, int n)
{
    int N = 100; // This function will generate random numbers for n=50 it will generate 50 numbers
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % N);
    }

    return arr;
}

void merge(vector<int>& arr, int start, int end)
{
    int mid = (start + end) / 2;

    int firstlen = mid - start + 1;
    int secondlen = end - mid;

    vector<int> firstList(firstlen);
    vector<int> secondList(secondlen);

    int p = start;
    for (int i = 0; i < firstlen; i++)
    {
        firstList[i] = arr[p];
        p++;
    }

    for (int i = 0; i < secondlen; i++)
    {
        secondList[i] = arr[p];
        p++;
    }

    int start1 = 0;
    int start2 = 0;

    while (start1 < firstlen && start2 < secondlen)
    {
        if (firstList[start1] < secondList[start2])
        {
            arr[start++] = firstList[start1++];
        }
        else
        {
            arr[start++] = secondList[start2++];
        }
    }

    while (start1 < firstlen)
    {
        arr[start++] = firstList[start1++];
    }

    while (start2 < secondlen)
    {
        arr[start++] = secondList[start2++];
    }
}

void mergeSort(vector<int>& arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, end);
    }
}

int main()
{
    vector<int> arr; // creating a dynamic array

    for(int input_size=1000;input_size<50000;input_size = input_size +1000){


    // generating random numbers
    arr = randomnumbers(arr, input_size);

    // to calculate time if an algorithm runs 100 times for a specific input
    clock_t start, end;

    start = clock();

    for (int i = 0; i < 100; i++)
        mergeSort(arr,0,arr.size()-1);

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

// Average Time taken by for input size 1000 is : 0.034000 sec 

// Average Time taken by for input size 2000 is : 0.11700 sec 

// Average Time taken by for input size 3000 is : 0.21800 sec 

// Average Time taken by for input size 4000 is : 0.32900 sec 

// Average Time taken by for input size 5000 is : 0.61900 sec 

// Average Time taken by for input size 6000 is : 0.70200 sec 

// Average Time taken by for input size 7000 is : 0.94100 sec 

// Average Time taken by for input size 8000 is : 1.23500 sec 

// Average Time taken by for input size 9000 is : 1.86900 sec 

// Average Time taken by for input size 10000 is : 1.91500 sec 

// Average Time taken by for input size 11000 is : 2.18000 sec

// Average Time taken by for input size 12000 is : 3.06500 sec

// Average Time taken by for input size 13000 is : 3.02500 sec

// Average Time taken by for input size 14000 is : 3.51100 sec

// Average Time taken by for input size 15000 is : 4.04000 sec

// Average Time taken by for input size 16000 is : 4.63600 sec

// Average Time taken by for input size 17000 is : 5.81400 sec

// Average Time taken by for input size 18000 is : 5.82600 sec

// Average Time taken by for input size 19000 is : 6.59000 sec

// Average Time taken by for input size 20000 is : 7.45800 sec