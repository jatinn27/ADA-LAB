#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;

vector<int> randomnumbers(vector<int> arr, int n)
{
    int N = 100;
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
}

int Sum(vector<int> &arr, int i,int size)
{

    if (size== 1)
    {
        return arr[i];
    }
    else
    {
        return arr[i] + Sum(arr, i + 1,size-1);
    }
}

int main()
{
    vector<int> arr;

    arr=randomnumbers(arr,5000);

    clock_t start, end;
    int x=0;
    start = clock();

    Sum(arr,x,arr.size());

    end = clock();
	double time_taken = double(end - start)/CLOCKS_PER_SEC;
    double average_time=time_taken/100;
	cout << "\nAverage Time taken by program is : " << fixed 
		<< time_taken << setprecision(5);
	cout << " sec " << endl;

    return 0;
}