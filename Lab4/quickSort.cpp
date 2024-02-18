#include <iostream>
#include <vector>
#include <iomanip> // setprecision()
#include <cstdlib> // clock_t
using namespace std;

void print(vector<int> &arr){
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

void quickSort(vector<int> &arr,int s,int e){
    if(s<e){
        int q = partition(arr,s,e);
        quickSort(arr,s,q-1);
        quickSort(arr,q+1,e);
    }
}

int main(){
    vector<int> arr; // creating a dynamic array

    for(int input_size=500;input_size<10000;input_size = input_size +100){


    // generating random numbers
    arr = randomnumbers(arr, input_size);

    // to calculate time if an algorithm runs 100 times for a specific input
    clock_t start, end;

    start = clock();

    for (int i = 0; i < 100; i++)
        quickSort(arr,0,arr.size()-1);

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

// Average Time taken by for input size 500 is : 0.034000 sec

// Average Time taken by for input size 600 is : 0.16300 sec

// Average Time taken by for input size 700 is : 0.43700 sec

// Average Time taken by for input size 800 is : 0.92900 sec

// Average Time taken by for input size 900 is : 1.65200 sec

// Average Time taken by for input size 1000 is : 2.66500 sec

// Average Time taken by for input size 1100 is : 4.23600 sec

// Average Time taken by for input size 1200 is : 6.30100 sec 

// Average Time taken by for input size 1300 is : 9.01200 sec 

// Average Time taken by for input size 1400 is : 12.31600 sec 

// Average Time taken by for input size 1500 is : 16.58200 sec