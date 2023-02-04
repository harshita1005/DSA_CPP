#include<iostream>
#include<queue>
#include<stack>
using namespace std;


class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

//creation of binary tree
node* buildtree(node* root){
    cout<<"Enter data "<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){ //null node
        return NULL;
    }
    cout<<"Enter data in left of "<<data<<endl;
    root->left=buildtree(root->left);

    cout<<"Enter data in right of "<<data<<endl;
    root->right=buildtree(root->right);

    return root;
}

int height(node* root){
    int x,y;
    if(root==NULL){
        return 0;
    }
    if(root!=NULL){
        x=height(root->left);
        y=height(root->right);
    }
    return max(x,y)+1;
}

int main()
{
 node* root=NULL;
 root=buildtree(root);

 cout<<"Height of given tree is- "<<height(root);
 return 0;
}
