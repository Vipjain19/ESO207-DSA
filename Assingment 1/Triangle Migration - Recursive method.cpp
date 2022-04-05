#include <time.h>
#include <cstdio>
#include <iostream>

using namespace std;
long int Lower(int);

long int Upper(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else return (3*Upper(n-1)+ Lower(n-1))%1000000007;
}
long int Lower(int n){
    if(n==1 || n==0) return 0;
    else return (Upper(n-1)+ 3*Lower(n-1))%1000000007;
}
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long int n;
    cin>>n;
    cout<<Upper(n+1);
    return 0;
}