class Solution {
public:
    void solve(TreeNode* root,TreeNode* &prev,int &f){
        if(root==NULL){
            return;
        }
        solve(root->left,prev,f);
        if(prev!=NULL && root->val <= prev->val){
            f=0;
            return;
        }
        prev=root;
        solve(root->right,prev,f);
    }
    bool isValidBST(TreeNode* root) {
        
        int f=1;
        TreeNode* prev=NULL;
        solve(root,prev,f);
        return f;
    
    }
};
*/
class Solution {
public:
    bool isBST(TreeNode* root,long min,long max){
        //base case
        if(root==NULL){
            return true;
        }
        if(root->val > min && root-> val <max){
            bool left=isBST(root->left,min,root->val);
            bool right=isBST(root->right,root->val,max);
            return left && right;
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root,LONG_MIN,LONG_MAX);
    }
};
