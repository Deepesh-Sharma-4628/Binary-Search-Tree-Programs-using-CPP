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

pair<int,int> InOrder_Predecessor_Successor_In_BST(Node* root,int key){
    Node* temp=root;
    int pred=-1;
    int succ=-1;

    //Find Key
    while(temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }
        else {
            pred=temp->data;
            temp=temp->right;
        }
    }

    //Find max element in leftsubtree(predecessor)
    Node* leftsubtree=temp->left;
    while(leftsubtree->right!=NULL){
        leftsubtree=leftsubtree->right;
    }
    pred=leftsubtree->data;

    //Find min element in rightsubtree(successor)
    Node* rightsubtree=temp->right;
    while(rightsubtree->left!=NULL){
        rightsubtree=rightsubtree->left;
    }
    succ=rightsubtree->data;

    return {pred,succ};
}

int main(){
    Node* root=NULL;
    root=TakeInput(root);
    int key;
    cout<<"Enter Key "<<endl;
    cin>>key;
    pair<int,int> ans=InOrder_Predecessor_Successor_In_BST(root,key);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}