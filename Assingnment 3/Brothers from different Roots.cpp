#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* createBST(int A[], int start, int end){
    if (start > end) return NULL;
    Node* temp = newNode(A[start]);
    int i;
    for (i = start; i <= end; i++){
        if (A[i] > temp->data) break;
    }   
    temp->left = createBST(A, start + 1, i - 1);
    temp->right = createBST(A, i, end);
    return temp;
 }

void inorder(Node* root, int A[], int* id){
    if(!root)return;
    inorder(root->left, A, id);
    A[(*id)++] = root->data;
    inorder(root->right, A, id);
    return;
}

int main() {
    int n1,n2,k;
    cin>>n1;
    int A[n1];
    for(int i=0;i<n1;i++) cin>>A[i];
    cin>>n2;
    int B[n2];
    for(int i=0;i<n2;i++) cin>>B[i];
    cin>>k;
    Node* root1 = createBST(A, 0, n1-1);
    Node* root2 = createBST(B, 0, n2-1);
    int id1=0,id2=0;
    inorder(root1,A,&id1);
    inorder(root2,B,&id2);
    int L=0, R=n2-1, count=0;
    while(L<n1 && R>=0){
        if(A[L]+B[R]==k){
            count++;R--;
        }
        if(A[L]+B[R]>k)R--;
        else L++;
    }
    cout<<count;
    return 0;
}