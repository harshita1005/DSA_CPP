/*
 class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>ans;
        queue<TreeNode*>q;
        TreeNode* t;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                t=q.front();
                q.pop();
                if(t->left!=NULL){
                    q.push(t->left);
                }
                if(t->right!=NULL){
                    q.push(t->right);
                }
            }
            ans.push_back(t->val);
        }
        return ans;

    }
};
*/
class Solution {
public:
    
    void solve(TreeNode* root, vector<int>&ans,int level){

        if(root==NULL){
            return;
        }
        //we entered into a new level
        if(level == ans.size()){
            ans.push_back(root->val);
        }
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
      
      vector<int>ans;
      solve(root,ans,0);
      return ans;
    }
};
