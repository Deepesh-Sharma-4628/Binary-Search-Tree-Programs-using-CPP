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

int LCA_BST(Node* root,int node1,int node2){
    while(root!=NULL){
        if(root->data<node1 && root->data<node2){
                root=root->right;
        }
        else if(root->data>node1 && root->data > node2){
            root=root->left;
        }
       else return root->data;
    }
}

int main(){
    Node* root=NULL;
    root=TakeInput(root);
    int node1,node2;
    cout<<"Enter Node1 data and Node2 data "<<endl;
    cin>>node1>>node2;
    cout<<LCA_BST(root,node1,node2);
    return 0;
}

////Time Complexity--> O(n)
////Space Complexity--> O(1)