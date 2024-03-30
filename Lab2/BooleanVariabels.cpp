#include <iostream>
#include <vector>
#include <iomanip> // setprecision()
#include <cstdlib> // clock_t
using namespace std;

void printComb(vector<bool> &arr, int index)
{
    if (index >= arr.size())
    {
        for (int i = 0; i < index; i++)
        {
            // cout << arr[i] << " ";
        }
        return;
    }

    arr[index] = true;
    printComb(arr, index + 1);

    arr[index] = false;
    printComb(arr, index + 1);
}

int main()
{
    for (int input_size = 1; input_size <= 100; input_size++)
    {
        vector<bool> var(input_size);

        clock_t start, end;

        start = clock();

        for (int j = 0; j < 100; j++)
            printComb(var, 0);

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

// Average Time taken by for input size 1 is : 0.000000 sec 

// Average Time taken by for input size 2 is : 0.00000 sec 

// Average Time taken by for input size 3 is : 0.00000 sec 

// Average Time taken by for input size 4 is : 0.00000 sec 

// Average Time taken by for input size 5 is : 0.00000 sec 

// Average Time taken by for input size 6 is : 0.00000 sec 

// Average Time taken by for input size 7 is : 0.00000 sec 

// Average Time taken by for input size 8 is : 0.00007 sec 

// Average Time taken by for input size 9 is : 0.00002 sec 

// Average Time taken by for input size 10 is : 0.00011 sec 

// Average Time taken by for input size 11 is : 0.00010 sec 

// Average Time taken by for input size 12 is : 0.00045 sec

// Average Time taken by for input size 13 is : 0.00076 sec

// Average Time taken by for input size 14 is : 0.00158 sec

// Average Time taken by for input size 15 is : 0.00300 sec

// Average Time taken by for input size 16 is : 0.00650 sec

// Average Time taken by for input size 17 is : 0.00999 sec

// Average Time taken by for input size 18 is : 0.02011 sec

// Average Time taken by for input size 19 is : 0.04113 sec

// Average Time taken by for input size 20 is : 0.08409 sec

// Average Time taken by for input size 21 is : 0.17699 sec