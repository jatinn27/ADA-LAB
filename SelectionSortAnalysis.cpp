#include <iostream>
#include <vector>
#include <iomanip> // setprecision()
#include <cstdlib> // clock_t
using namespace std;

vector<int> randomnumbers(vector<int> arr, int n)
{
    int N=100;      // This function will generate random numbers for n=50 it will generate 50 numbers
    for (int i = 0; i < n; i++){
        arr.push_back(rand() % N); 
    }

    return arr;
}

void print(vector<int>arr){
    // to print the numbers generated 
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

// Function for Selection sort 
void SelectionSort(vector<int> &arr)
{
    int min;
    for (int i = 0; i < arr.size(); i++)
    {
        min = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            swap(arr[min], arr[i]);
        }
    }
}

int main()
{
    vector<int> arr; // creating a dynamic array

    //generating random numbers
    arr=randomnumbers(arr,500);

    // to calculate time if an algorithm runs 100 times for a specific input 
    clock_t start, end;

    start = clock();

    for(int i=0;i<100;i++)
    SelectionSort(arr);

    end = clock();
    // total time taken for running an algorithm 100 times for a specific input  
	double time_taken = double(end - start)/CLOCKS_PER_SEC;
    //avearge time time_taken/100
    double average_time=time_taken/100;

	cout << "\nAverage Time taken by program is : " << fixed 
		<< time_taken << setprecision(5);
	cout << " sec " << endl;
	
    return 0;
}
