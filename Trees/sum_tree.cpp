class Solution
{
    public:
    bool ans=true;
    int  check(Node *root)
    {
        if(root==NULL)
        return 0;
        int leftsum=check(root->left);
        int rightsum=check(root->right);
        
        if(root->data!=leftsum+rightsum && (root->left!=NULL||root->right!=NULL))
        {
            ans=false;
            return 0;
        }
        return leftsum+rightsum+root->data; 
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         if(root==NULL)
         return true;
         check(root);
         return ans;
    }
};
