class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        //if both tree are empty
        if(p==NULL && q==NULL){
            return true;
        }
        
        //if one tree is empty and other is not
        if(p!=NULL&&q==NULL || p==NULL&&q!=NULL){
            return false;
        }
       
        bool left = isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        bool con=false;
        
        if(p->val == q->val){
            con = true;
        }
        
        if(left && right && con){
            return true;
        }
        return false;
        
    }
    
};
