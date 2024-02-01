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

// Average Time taken by for input size 1000 is : 0.000000 sec 

// Average Time taken by for input size 21000 is : 0.02400 sec 

// Average Time taken by for input size 41000 is : 0.07200 sec 

// Average Time taken by for input size 61000 is : 0.08000 sec 

// Average Time taken by for input size 81000 is : 0.12000 sec 

// Average Time taken by for input size 101000 is : 0.14400 sec 

// Average Time taken by for input size 121000 is : 0.15200 sec 

// Average Time taken by for input size 141000 is : 0.19500 sec 

// Average Time taken by for input size 161000 is : 0.19800 sec 

// Average Time taken by for input size 181000 is : 0.29800 sec 

// Average Time taken by for input size 201000 is : 0.28600 sec

// Average Time taken by for input size 221000 is : 0.32700 sec

// Average Time taken by for input size 241000 is : 0.33200 sec

// Average Time taken by for input size 261000 is : 0.32900 sec

// Average Time taken by for input size 281000 is : 0.43100 sec

// Average Time taken by for input size 301000 is : 0.43800 sec

// Average Time taken by for input size 321000 is : 0.45300 sec

// Average Time taken by for input size 341000 is : 0.44800 sec

// Average Time taken by for input size 361000 is : 0.48000 sec

// Average Time taken by for input size 381000 is : 0.53000 sec

// Average Time taken by for input size 401000 is : 0.59100 sec

// Average Time taken by for input size 421000 is : 0.50100 sec

// Average Time taken by for input size 441000 is : 0.58000 sec

// Average Time taken by for input size 461000 is : 0.54300 sec

// Average Time taken by for input size 481000 is : 0.52700 sec

// Average Time taken by for input size 501000 is : 0.64500 sec

// Average Time taken by for input size 521000 is : 0.77100 sec

// Average Time taken by for input size 541000 is : 0.82100 sec

// Average Time taken by for input size 561000 is : 0.74300 sec

// Average Time taken by for input size 581000 is : 0.76300 sec

// Average Time taken by for input size 601000 is : 0.76300 sec

// Average Time taken by for input size 621000 is : 1.11100 sec

// Average Time taken by for input size 641000 is : 0.92600 sec

// Average Time taken by for input size 661000 is : 0.86100 sec

// Average Time taken by for input size 681000 is : 0.89000 sec

// Average Time taken by for input size 701000 is : 0.98000 sec

// Average Time taken by for input size 721000 is : 1.68400 sec

// Average Time taken by for input size 741000 is : 2.28000 sec

// Average Time taken by for input size 761000 is : 2.34900 sec

// Average Time taken by for input size 781000 is : 2.36600 sec

// Average Time taken by for input size 801000 is : 2.42300 sec

// Average Time taken by for input size 821000 is : 2.53100 sec

// Average Time taken by for input size 841000 is : 2.63400 sec

// Average Time taken by for input size 861000 is : 2.70500 sec

// Average Time taken by for input size 881000 is : 3.00100 sec

// Average Time taken by for input size 901000 is : 2.96100 sec

// Average Time taken by for input size 921000 is : 1.15000 sec

// Average Time taken by for input size 941000 is : 1.20600 sec

// Average Time taken by for input size 961000 is : 1.23100 sec

// Average Time taken by for input size 981000 is : 1.35800 sec
