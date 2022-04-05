#include <iostream>
using namespace std;

bool isvalid(int x,int y,int R,int C){
    if(x>=0 && x<R && y>=0 && y<C) return true;
    return false;
}
int main() {   
    int R,C;
    cin>>R>>C;
    int A[R][C];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>A[i][j];
        }
    }
    int start=0,end=-1,ans=0;
    int Qx[2*R*C],Qy[2*R*C];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(A[i][j]==2){
                Qx[++end]=i;
                Qy[end]=j;
            }
        }
    }
    Qx[++end]=-1;Qy[end]=-1;
    while(start<=end){
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        bool fl=false;
        while(Qx[start]!=-1){
            int x=Qx[start];int y=Qy[start++];
            for(int k=0;k<4;k++){
                if(isvalid(x+dx[k],y+dy[k],R,C) && A[x+dx[k]][y+dy[k]]==1){
                    A[x+dx[k]][y+dy[k]]=2;
                    Qx[++end]=x+dx[k];Qy[end]=y+dy[k];
                    if(!fl){
                        ans++;fl=true;
                    }
                }
            }
        }
        start++;
        if(start<=end){
            Qx[++end]=-1;Qy[end]=-1;
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(A[i][j]==1){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<ans;
    return 0;
}