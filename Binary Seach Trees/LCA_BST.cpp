/*
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL){
            return NULL;
        }
        if(root==p || root==q){
            return root;
        }
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        return root;
    }
};
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
        while(root!=NULL){

            if(root->val < p->val && root->val <q->val){
                root=root->right;
            }
            else if( root->val > p->val && root->val > q->val){
                root=root->left;
            }
            else{
                return root;
            }
        
    }
    return root;
    }
};
