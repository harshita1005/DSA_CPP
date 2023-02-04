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


//reverse level order traversal using stack and queue
void reverse_level_order_traversal(node* root){
    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    stack<int> s; 

    node* temp = NULL;
    
    while(!q1.empty()){
        temp = q1.front();
        q1.pop();

        if( temp== NULL){   // // purana level complete traverse ho chuka hai
            s.push(0); // because s.push(temp -> data ) will give error as temp is null
            if(!q1.empty()){
                q1.push(NULL); 
            }
        }
        else{
            s.push(temp -> data); // as stack uses FIRST IN LAST OUT method so the first node entered in stack that is root node will be at the last and so on
            if(temp -> left){ 
                q1.push(temp -> left);
            }
            if(temp -> right){
                q1.push(temp -> right);
            }
        }
    }
    while(!s.empty()){
        if(s.top() == 0){
            s.pop();
            cout<<endl;
        }
        else{
            cout<< s.top() << " ";
            s.pop();
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
 reverse_level_order_traversal(root);
 return 0;
}
