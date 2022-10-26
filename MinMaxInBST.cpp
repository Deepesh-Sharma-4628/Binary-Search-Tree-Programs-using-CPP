#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node*  BST(Node* root,int data){
if(!root) {
    root=new Node(data);
    return root;
}
if(data <= root->data)
root->left=BST(root->left,data);

else root->right=BST(root->right,data);
return root;
}

void TakeInput(Node* &root){
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;
    while(data!=-1){
       
        root=BST(root,data);
         cin>>data;
    }
}

int MinEleInBST(Node* root){
    if(!root) return 0;
    if(!root->left) return root->data;
    return MinEleInBST(root->left);
}

int MaxEleInBST(Node* root){
    if(!root) return 0;
    if(!root->right) return root->data;
    return MaxEleInBST(root->right);
}

int MinBST_Iterative(Node* root ){
Node* temp=root;
while(temp->left){
    temp=temp->left;
}
return temp->data;
}


int MaxBST_Iterative(Node* root ){
Node* temp=root;
while(temp->right){
    temp=temp->right;
}
return temp->data;
}

int main(){
    Node* root=NULL;
    TakeInput(root);
    cout<<endl<<MinEleInBST(root)<<endl;
    cout<<MaxEleInBST(root)<<endl;
    cout<<endl<<MinEleInBST(root)<<endl;
    cout<<MaxEleInBST(root)<<endl;
    return 0;
}