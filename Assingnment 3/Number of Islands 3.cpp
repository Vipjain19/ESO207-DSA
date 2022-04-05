#include <iostream>
using namespace std;


bool isvalid(int x,int y,int R,int C){
    if(x>=0 && x<R && y>=0 && y<C) return true;
    return false;
}

void DFS(int R, int C, int** M, int i, int j, bool **vis){
    static int r[] = { -1, 0, 0, 1};
    static int c[] = {  0,-1, 1, 0};
    vis[i][j] = true;
    for (int k = 0; k < 4; k++){
        if (isvalid(i + r[k], j+ c[k],R,C) && M[i + r[k]][j+ c[k]] && !vis[i + r[k]][j+ c[k]])
            DFS(R, C, M, i + r[k], j + c[k], vis);
    }
}


int count(int R, int C,int** M)
{
 
    bool **vis= new bool*[R];
    for (int i = 0; i < R; i++)
        vis[i] = new bool[C];
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            vis[i][j]=false;
        }
    }
    int count = 0;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (M[i][j] && !vis[i][j]) {
                DFS(R, C, M, i, j, vis);
                count++;
            }
        }
    }
    return count;
}

int main(){
    int R,C;
    cin>>R>>C;
    int** M = new int*[R];
    for (int i = 0; i < R; i++)
        M[i] = new int[C];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>M[i][j];
        }
    }
    cout << count(R,C,M);
    return 0;
}

