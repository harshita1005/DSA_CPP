/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int answer;
int prev;
    void solve(TreeNode* root){

        if(!root) return;

        //going to left side
        solve(root->left);
        if(prev != INT_MAX){
            answer =min(root->val - prev, answer);
        }
        prev=root->val;
        
        //going to right side
        solve(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        
        answer=INT_MAX;
        prev=INT_MAX;
        solve(root);
        return answer;
    }
};
