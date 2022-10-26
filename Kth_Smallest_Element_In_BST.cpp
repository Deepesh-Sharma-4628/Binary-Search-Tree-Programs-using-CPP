#include<iostream>
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

void CreateBST(Node* &root,int data){
if(!root){
    root=new Node(data);
    return ;
}
if(root->data<data)
    CreateBST(root->right,data);
else
    CreateBST(root->left,data);
}

Node* TakeInput(Node* root){
    int data;
    cout<<"ENTER  DATA"<<endl;
    cin>>data;
    while(data!=-1){
        CreateBST(root,data);
        cout<<"ENTER OF DATA"<<endl;
        cin>>data;
    }
    return root;
}

int KthSmallestElement_BST(Node* root,int &i,int k){
    if(root==NULL)return -1;
    int left=KthSmallestElement_BST(root->left,i, k);
    if(left!=-1)return left;
    i++;
    if(i==k){
        return root->data;
    }
    return KthSmallestElement_BST(root->right,i,k);

}
int main(){
Node* root=NULL;
root=TakeInput(root);
int k, i=0;
cout<<"Enter K Value"<<endl;
cin>>k;
int ans=KthSmallestElement_BST(root,i,k);
cout<<ans;
}

////Time Complexity--> O(n)
////Space Complexity--> O(Height Of Tree)