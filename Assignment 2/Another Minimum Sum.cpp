#include <iostream>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    int a[n];
    int min[n];
    int max[n];
    //int mins[n];
    //int maxs[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    min[0]=a[0];max[0]=a[0];
    //mins[0]=0;maxs[0]=0;
    for(int i=1;i<n;i++){
        if(max[i-1]>0){
            max[i]=a[i]+max[i-1];
            //maxs[i]=maxs[i-1];
        }
        else{
            max[i]=a[i];
            //maxs[i]=i;
        }
        if(min[i-1]<0){
            min[i]=min[i-1]+a[i];
           // mins[i]=mins[i-1];
        }
        else{
            min[i]=a[i];
            //mins[i]=i;
        }
    }
    int ans=1000001;
    for(int i=0;i<n;i++){
        if(max[i]>k){
            if(min[i]<ans){
                if(min[i]>k){
                    ans=min[i];
                }
                else{
                    int temp=a[i];
                    int j=i-1;
                    if(temp>k && temp<ans) ans=temp;
                    while(j>=0){
                        if(temp+max[j]<=k) break;
                        if(temp+min[j]>k){
                            if(temp+min[j]<ans) ans=temp+min[j];
                            break;
                        }
                        temp+=a[j];
                        if(temp>k && temp<ans) ans=temp;
                        j--;
                    }
                    if(ans==k+1) break;
                }
            }
        }
    }
    if(ans==1000001) cout<<"-1";
    else cout<<ans;
    return 0;
}