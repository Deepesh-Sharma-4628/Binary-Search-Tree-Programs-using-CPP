#include<iostream>
#include<queue>
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
    cout<<"ENTER  OF DATA"<<endl;
    cin>>data;
    while(data!=-1){
        CreateBST(root,data);
        cout<<"ENTER DATA"<<endl;
        cin>>data;
    }
    return root;
}

bool ValidateBST(Node* root,int min,int max){
    if(root==NULL)return true;
    if(root->data>=min && root->data<=max){
        bool left =ValidateBST(root->left,min,root->data);
        bool right= ValidateBST(root->right,root->data,max);
        return left && right;
    }
    else return false;
}


int main(){
Node* root=NULL;
root=TakeInput(root);
bool ans=ValidateBST(root,INT_MIN,INT_MAX);
cout<<ans;
}

////Time Complexity--> O(n)
////Space Complexity--> O(Height Of Tree)