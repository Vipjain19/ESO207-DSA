#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};
 
struct node* newNode(int item){
    struct node* temp = new struct node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key){
    if (node == NULL)         return newNode(key);
    if (key < node->key)      node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    return node;
}


int Nodedistance(struct node* root, int x) 
{ 
    if (root->key == x)      return 0; 
    else if (root->key > x)  return 1 + Nodedistance(root->left, x); 
    return 1 + Nodedistance(root->right, x); 
} 
  
int Finaldistance(struct node* root, int a, int b) 
{ 
    if (!root)  return 0; 
    if (root->key > a && root->key > b)   return Finaldistance(root->left, a, b); 
    if (root->key < a && root->key < b)   return Finaldistance(root->right, a, b); 
    if (root->key >= a && root->key <= b) return (1+Nodedistance(root, a)+Nodedistance(root, b)); 
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,K;
    cin>>N>>K;
    struct node* root = NULL;
    int temp;
    cin>>temp;
    root=insert(root,temp);
    for(int i=1;i<N;i++){
        cin>>temp;
        insert(root,temp);
    }
    for(int i=1;i<=K;i++){
        int a,b;
        cin>>a>>b;
        if(b<a){
            temp=b;
            b=a;a=temp;
        }
        cout<<Finaldistance(root,a,b)<<"\n";
    }
    return 0;
}
