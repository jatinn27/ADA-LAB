#include <iostream>
using namespace std;

int FASTESTWAY(int a[][4], int t[][4], int e[], int x[]){
    int f1[4];
    int f2[4];
    
    f1[1]=e[1]+a[1][1];
    f2[1]=e[2]+a[2][1];
    
    for(int j=2; j<4; j++){
        if(f1[j-1]+a[1][j]<=f2[j-1]+t[2][j-1]+a[1][j]){
            return f1[j]=f1[j-1]+a[1][j];
        }
            else
                f1[j]=f2[j-1]+t[2][j-1]+a[1][j];
        if(f2[j-1]+a[2][j]<=f1[j-1]+t[1][j-1]+a[2][j]){
            return f2[j]=f2[j-1]+a[2][j];
        }
            else
                f2[j]=f1[j-1]+t[1][j-1]+a[2][j];
            
        if(f1[4]+x[1]<=f2[4]+x[2]){
             return f1[0]=f1[4]+x[1];
        }
        
            else
                return f2[0]=f2[4]+x[2];
        
    }
    
}

int main(){
    int a[][4] = {{1, 2, 3, 4},  {5, 6, 7, 8}};  
    int t[][4] = {{0, 4, 3, 5},   {0, 6, 2, 9}};  
    int e[] = {14, 13};
    int x[] = {14, 5}; 
    
    cout<<FASTESTWAY(a,t,e,x);
    
    return 0;
}
