#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> DCM(vector<vector<int>> &A,vector<vector<int>> &B,vector<vector<int>> &res,int n){
    if(n==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res[i][j]=0;
                for(int k=0;k<n;k++){
                    res[i][j] = res[i][j] + A[i][j] * B[i][j];
                }
            }
        }

        return res;
    }else{
        DCM(A[0][0],B[0][0],res,n/2);
    }

}

int main(){
    
    return 0;
}