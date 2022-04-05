#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0;
 
    int j = 0;
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void countsort(int A[],int S[],int l,int r,int n){
    if(l>=r) return;
    int mid=(l+r)/2;
    countsort(A,S,l,mid,n);
    for(int i=mid+1;i<=r;i++){
        int L=l;int R=mid;
        int m=(L+R)/2;
        while(L<=R){
            m=(L+R)/2;
            if(A[m]>=A[i]){
                if(m>L && A[m-1]>=A[i]){
                    R=m-1;
                }
                else break;              
            }else{
                L=m+1;
            }
        }
        if(m==mid){
            if(A[m]>=A[i]) S[i]+=1;
        }
        else{
            S[i]+= mid-m+1;
        }
    }
    countsort(A,S,mid+1,r,n);
    merge(A,l,mid,r);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];
    int S[n];
    for(int i=0;i<n;i++) S[i]=0;
    countsort(A,S,0,n-1,n);
    for(int i=0;i<n;i++) cout<<S[i]<<" ";
    return 0;
}