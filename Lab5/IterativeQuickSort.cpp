#include <iostream>
#include <vector>
#include <iomanip> // setprecision()
#include <cstdlib> // clock_t
using namespace std;
 
int partition(int arr[],int start,int end){
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

void quickSortIterative(int arr[], int l, int h) 
{ 
    int stack[h - l + 1]; 

    int top = -1; 

    stack[++top] = l; 
    stack[++top] = h; 

    while (top >= 0) { 
        h = stack[top--]; 
        l = stack[top--]; 

        int p = partition(arr, l, h); 

        if (p - 1 > l) { 
            stack[++top] = l; 
            stack[++top] = p - 1; 
        } 

        if (p + 1 < h) { 
            stack[++top] = p + 1; 
            stack[++top] = h; 
        } 
    } 
} 

int main() 
{ 

	int n = 5; 
	int arr[5] = { 4, 2, 6, 9, 2 }; 

	quickSort(arr, 0, n - 1); 

	for (int i = 0; i < n; i++) { 
		cout << arr[i] << " "; 
	} 

	return 0; 
} 
