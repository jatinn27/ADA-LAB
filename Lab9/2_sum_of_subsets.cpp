#include<iostream>
#include<vector>
using namespace std;

void sum_of_subsets(vector<int> &x,vector<int> &w,int s,int k,int r,int m){
    x[k] = 1;

    if(s + w[k] == m){
        for(int i=0;i<x.size();i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }else if(s + w[k] + w[k+1] <= m){
        sum_of_subsets(x,w,s+w[k],k+1,r-w[k],m);
    }
    x[k] = 0;
    if((s + r - w[k] >=m ) && s+w[k+1] <=m){
        sum_of_subsets(x,w,s,k+1,r-w[k],m);
    }
}

int main(){
    vector<int> w= {5,10,12,13,15,18};
    vector<int> x(w.size(),0);

    sum_of_subsets(x,w,0,0,73,30);

    return 0;
}