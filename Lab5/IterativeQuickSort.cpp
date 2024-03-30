#include <iostream>
#include <vector>
#include <iomanip> // setprecision()
#include <cstdlib> // clock_t
#include <stack>
using namespace std;

void print(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> randomnumbers(int n)
{
    vector<int> arr;
    int N = 100;
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

void IterativeQS(vector<int> &arr, int low, int high, int &recCalls)
{
    stack<pair<int, int>> st;
    while (1)
    {
        while (low < high)
        {
            int j = partition(arr, low, high);
            if (j - low > high - j)
            {
                st.push({low, j - 1});
                low = j + 1;
                recCalls++;
            }
            else
            {
                st.push({j + 1, high});
                high = j - 1;
                recCalls++;
            }
            cout << "Recursive Calls Made are:- " << recCalls << endl;
        }
        if (st.empty())
        {
            recCalls--;
            return;
        }
        low = st.top().first;
        high = st.top().second;
        st.pop();
    }
}

int main(){
    int n = 8; 
    vector<int> arr = randomnumbers(n);
    cout << "Original Array:" << endl;
    print(arr); 

    int recCalls = 0;
    IterativeQS(arr, 0, arr.size() - 1, recCalls); 

    cout << "\nSorted Array:" << endl;
    print(arr); 

    cout << "\nNumber of Recursive Calls: " << recCalls << endl;
    
    return 0;
}
