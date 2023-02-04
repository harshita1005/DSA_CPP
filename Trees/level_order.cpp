#include<iostream>
#include<queue>
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


//level order traversal
void level_order_traversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);


    while(!q.empty()){
        node* temp=q.front();
        
        q.pop();

        if(temp==NULL){
            cout<<endl;    //if null ata hai hit a new line to print next level
            if(!q.empty()){
                //queue has some child so aat the end will add null
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
             if(temp->left!=NULL){
                q.push(temp->left);
        }
            if(temp->right!=NULL){
                q.push(temp->right);
    }

    }
    }

}
int main()
{
 node* root=NULL;
 root=buildtree(root);
 //level order traversal printing
 //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
 cout<<endl;
 cout<<"Printing level order traversal"<<endl;
 level_order_traversal(root);
 return 0;
}
