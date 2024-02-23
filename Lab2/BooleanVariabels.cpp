#include<iostream>
#include<vector>
using namespace std;

void printComb(vector<bool> &arr,int index){
    if(index >= arr.size()){
        for(int i=0;i<index;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }

    arr[index] = true;
    printComb(arr,index+1);

    arr[index] = false;
    printComb(arr,index+1);
}

int main(){
    int n;
    cout<<"Enter the total boolean variables ";
    cin>>n;
    vector<bool> var(n);

    printComb(var,0);
    
    return 0;
}