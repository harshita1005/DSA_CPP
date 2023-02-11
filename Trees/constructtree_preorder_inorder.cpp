class Solution {
public:
    void createMapping(vector<int>inorder, map<int,int> &nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& inorder,vector<int>& preorder,int &index,int startInorder,int endInorder,int n,map<int,int> &nodeToIndex )
    {
        if(index>=n || startInorder > endInorder){
            return NULL;
        }
        //create a root node for element
        int element=preorder[index++];
        TreeNode* root=new TreeNode(element);

        //find element's position in inorder
        int position=nodeToIndex[element];

        root->left=solve(inorder,preorder,index,startInorder,position-1,n,nodeToIndex);
        root->right=solve(inorder,preorder,index,position+1,endInorder,n,nodeToIndex);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        /*Algo:
        1.Take index element as root element from preorder
        2.Find position of root element in inorder
        3.give a right and left call from position of element
        */
        int preOrderIndex=0;
        //creating map to store the index of each nodes
        map<int,int> nodeToIndex;
         int n=preorder.size();
        createMapping(inorder, nodeToIndex,n);
       
        TreeNode* ans= solve(inorder,preorder,preOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};
