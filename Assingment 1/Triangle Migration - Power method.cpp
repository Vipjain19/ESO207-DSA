#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

long long int** multiply (long long** arr1,long long** arr2){
    long long int** ans = new long long int*[2] ;
    ans[0]= new long long int[2];
    ans[1]= new long long int[2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ans[i][j] = 0;
            for(int k=0;k<2;k++){
                ans[i][j] += (arr1[i][k]*arr2[k][j])%1000000007;
            }
            ans[i][j]%=1000000007;
        }
    }
    return ans;
}
long long int** power(long long **arr,long long n){
    if(n==1 || n==0) return arr;
    else{
        long long int** arr2 = power(arr,n/2);
        if(n%2==0){
            return multiply(arr2,arr2);
        }
        else{
            return multiply(multiply(arr2,arr2),arr);
        }
    }
}
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int** arr = new long long int*[2] ;
    arr[0]= new long long int[2];
    arr[1]= new long long int[2];
    arr[0][0]=3;arr[0][1]=1;arr[1][0]=1;arr[1][1]=3;
    long long n;
    cin>>n;
    long long int** ans = power(arr,n); 
    if(n==0){
        ans[0][0]=1;ans[0][1]=0;
    }
    cout <<ans[0][0]<<", "<<ans[0][1];
    return 0;
}