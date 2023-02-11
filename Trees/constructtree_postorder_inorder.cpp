class Solution {
public:
    void createMapping(vector<int>inorder, map<int,int> &nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int &index,int startInorder,int endInorder,int n,map<int,int> &nodeToIndex )
    {
        if(index<0 || startInorder > endInorder){
            return NULL;
        }
        //create a root node for element
        int element=postorder[index--];
        TreeNode* root=new TreeNode(element);

        //find element's position in inorder
        int position=nodeToIndex[element];

        root->right=solve(inorder,postorder,index,position+1,endInorder,n,nodeToIndex);
        root->left=solve(inorder,postorder,index,startInorder,position-1,n,nodeToIndex);
        

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        /*Algo:
        1.Take end index element as root element from preorder
        2.Find position of root element in inorder
        3.give a right and left call from position of element
        */
         int n=inorder.size();
        int postOrderIndex=n-1;
        //creating map to store the index of each nodes
        map<int,int> nodeToIndex;
        
        createMapping(inorder, nodeToIndex,n);
       
        TreeNode* ans= solve(inorder,postorder,postOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};
