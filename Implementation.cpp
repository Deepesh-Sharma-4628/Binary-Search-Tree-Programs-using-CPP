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

void BFS(Node* root){
queue<Node*>Q;
Q.push(root);
Q.push(NULL);
Node* temp=NULL;
while(!Q.empty()){
temp=Q.front();
Q.pop();
if(temp==NULL){
    cout<<endl;
    if(!Q.empty()){
        Q.push(NULL);
    }
}
else{
cout<<temp->data<<" ";
if(temp->left)Q.push(temp->left);
if(temp->right)Q.push(temp->right);
        }
    }
}


int main(){
Node* root=NULL;
TakeInput(root);
BFS(root);
}
/////Time complexity--: O(logn)