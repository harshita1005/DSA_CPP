class Solution {
public:
    vector<int>i;
    //get the inorder traversal of the given tree and store it in vector i
    void in(TreeNode* root)
    {
        if(!root)
            return;
        in(root->left);
        i.push_back(root->val);
        in(root->right);
    }
    //once you get the inorder traversal ..generate the bst out of it
    TreeNode* build(int s,int e)
    {
        //if s crosses e then return NULL
        if(s>e)
            return NULL;
        //the root node will be of the middle value in inorder traversal
        int mid=s+(e-s)/2;
        //assign the roor's value
        TreeNode* root=new TreeNode(i[mid]);
        //the elements on left of root will be smaller hence the array which will form the left subtree will be from s to mid-1
        root->left=build(s,mid-1);
        //for right subtree we want elements greater than mid .. hence the array will be between mid+1 and e
        root->right=build(mid+1,e);
        // once the root is formed return it 
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        in(root);
        return build(0,i.size()-1);
    }
};
