
/*
class Solution {
public:

 

    pair<int,int> diameterfast(TreeNode* root){ //storing diameter in first and height in second

        //three conditions for calculating diameter
        //op1- diameter in left subtree
        //op2- diameter in right subtree
        //op3- diameter in left +right+node i.e height

        //base case
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }

        pair<int,int> left=diameterfast(root->left);
        pair<int,int> right=diameterfast(root->right);

        int op1=left.first;         //first-diameter
        int op2=right.first;
        int op3=left.second+right.second+1;

        pair<int,int>ans;
        ans.first=max(op1,max(op2,op3));    //calculating the diameter
        ans.second=max(left.second,right.second)+1; //calculating height

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        return diameterfast(root).first;
    }
};

*/

class Solution {
public:


int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter = 0;
        height(root,diameter);
        return diameter;
        
    }

    int height(TreeNode* node, int& diameter){

        if(!node) return 0;

        int lh = height(node->left,diameter);
        int rh = height(node->right,diameter);
        diameter = max(diameter,lh+rh);

        return 1 + max(lh,rh);

    }
};
