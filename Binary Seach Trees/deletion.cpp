class Solution {
public:
    TreeNode* minVal(TreeNode* root){                      //predecessor
    TreeNode* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    
    return temp;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    //BASE CASE
    if(root==NULL)return root;
    
    //TARGET FOUND
    if(root->val==key){
        //FOR 0 CHILD
        if(root->left==NULL and root->right==NULL){
            delete root;
            return NULL;
        }
        
        // FOR ONE CHLID
        
           //left chlid
        if(root->left!=NULL and root->right==NULL){
            TreeNode* temp=root->left;
            delete root;
            return temp;
        }
        
           //Right chlid
        if(root->left==NULL and root->right!=NULL){
            TreeNode* temp=root->right;
            delete root;
            return temp;
        }
        
        //For 2 chlid
        
        if(root->left!=NULL and root->right!=NULL){
            int mini=minVal(root->right)->val;
            root->val=mini;
            root->right=deleteNode(root->right,mini);
            return root;
        }
    }
    
    if(root->val >key){
        //GO TO LEFT PART
        root->left=deleteNode(root->left,key);
    }else{
        //GO TO RIGHT PART
        root->right=deleteNode(root->right,key);
    }
    
    return root;
}
};
