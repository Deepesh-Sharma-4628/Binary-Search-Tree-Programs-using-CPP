#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* CreateBST(Node* root,int data){
    if(!root){
        root=new Node(data);
        return root;
    }
    if(root->data < data)
    root->right=CreateBST(root->right,data);
    else root->left=CreateBST(root->left,data);
    return root;
}

void TakeInput(Node* &root){
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;
    while(data!=-1){
        root=CreateBST(root,data);
        cin>>data;
    }
}

int MinBST(Node* root){
    if(!root->left) return root->data;
    return MinBST(root->left);
}
Node* DeleteNodeBST(Node* root,int key){
    if(!root) return root;
    if(root->data == key){
        //Delete node code
        //for 0 child
        if(!root->left && !root->right){
            delete(root);
            return NULL;
        }
        //for 1 child

        //for left child
        else if(!root->right && root->left){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        // for right child
         else if(root->right && !root->left){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        //for 2 child
        else{
            int mini=MinBST(root->right);
            root->data=mini;
            root->right=DeleteNodeBST(root->right,mini);
        }
    }
    else if(root->data < key)
    root->right=DeleteNodeBST(root->right,key);
    else root->left=DeleteNodeBST(root->left,key);
    return root;
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
    int key;
    cin>>key;
    root=DeleteNodeBST(root,key);
    cout<<endl;
    BFS(root);
    return 0;
}