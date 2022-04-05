#include <iostream>
#include <cstdio>
#include <time.h>

using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    long Upper=1;long Lower=0;
    for(int i=1;i<=n;i++){
        long tUpper = (3*Upper + Lower)%1000000007;
        Lower = (Upper + 3*Lower)%1000000007;
        Upper = tUpper;
    }
    if(n==0) Upper=1;
    cout<<Upper;
    return 0;
}