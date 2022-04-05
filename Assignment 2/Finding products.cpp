#include <iostream>

using namespace std;

int search(int B[],int l,int r,int key){
    int m;
    if(l>=r)  return l;
    while(l<r){
        m=(l+r)/2;
        if(B[m]<=key){
            if(B[m+1]>key) return m;
            else l=m+1;
        }
        else r=m-1;
    }
    return l;
}
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
 
    while (i < n1 && j < n2){
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
 
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int M,N;
    cin>>M>>N;
    int A[M],B[N];
    for(int i=0;i<M;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
    long int k;
    cin>>k;
    int L1=0,L2=0,R1=M-1,R2=N-1;
    int l[M],r[M],m[M],f[M];
    int fl=0;
    for(int i=0;i<M;i++) l[i]=0;
    for(int i=0;i<M;i++) r[i]=N-1;
    for(int i=0;i<M;i++) f[i]=1;
    int m1,m2;
    while(L1+1<R1 && L2+1<R2){
        m1=(L1+R1)/2;m2=(L2+R2)/2;
        int temp=A[m1]*B[m2];
        long int count=0;
        for(int i=0;i<M;i++){
            int key = temp/A[i];
            if(B[l[i]]<=key) {
                m[i] = search(B,l[i],r[i],key);
                count += m[i]+1;
            }else{
                m[i]=l[i];
                count+=l[i];
            }
        }
        if(count==k){
            fl=1;
            break;
        }
        else if(count>k){
            for(int i=0;i<M;i++){
                r[i]=m[i];
                if(l[i]==r[i] && B[l[i]]*A[i]>temp) f[i]=0;
            } 
            R1=m1;R2=m2;
        }
        else{
            for(int i=0;i<M;i++) l[i]=m[i];
            L1=m1;L2=m2;
        }
    }
    if(fl) cout<<A[m1]*B[m2];
    else{
        long int kl=0;
        long size=0;
        for(int i=0;i<M;i++){
            kl+=l[i];
            if(f[i]) size+=r[i]-l[i]+1;
        }
        int arr[size];
        long int p=0;
        for(int i=0;i<M;i++){
            if(f[i]){
            for(int j=l[i];j<=r[i];j++){
                arr[p]=A[i]*B[j];
                p++;
                if(p>=size) break;
            }
            if(p>=size) break;
            }
        }
        mergeSort(arr,0,size-1);
        cout<<arr[k-kl-1];
    }
    return 0;
}