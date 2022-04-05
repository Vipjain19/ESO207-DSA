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

void preorder(Node* root){
    if(!root)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

void greater_tree(Node* root, int* sum){
    if(!root)return;
    greater_tree(root->right, sum);
    root->data = root->data + *sum;
    *sum = root->data;
    greater_tree(root->left, sum);
}

int main(){
    int N,sum = 0;
    cin>>N;
    int A[N];
    for(int i=0; i<N; i++) cin>>A[i];
    Node* root = createBST(A, 0, N-1);
    greater_tree(root, &sum);
    preorder(root);
    return 0;
}