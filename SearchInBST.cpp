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
    while(data!=-1){
        cin>>data;
        root=BST(root,data);
    }
}

bool FindKeyInBST(Node* root,int key){
    if(!root) return false;
    if(root->data == key) return true;
    if(root->data < key) return FindKeyInBST(root->right,key);
    else return FindKeyInBST(root->left,key); 
}

bool SearchInBST(Node* root,int key){
    Node* temp=root;
    while(temp){
        if(temp->data==key) return true;
        if(temp->data >key)
        temp=temp->left;
        else temp=temp->right;
    }
    return false;
}

int main(){
Node* root=NULL;
TakeInput(root);
cout<<endl;
int key;
cin>>key;
cout<<endl;
cout<<SearchInBST(root,key)<<endl;////iterative way
cout<<FindKeyInBST(root,key);////recursive way

}