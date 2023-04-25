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
 /*iterative approach- 

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        queue<pair<TreeNode*, int>> q; // <TreeNode*, sumSoFar>
        q.push({root, 0});

        while(!q.empty()){
            auto [root, currentSum] = q.front(); q.pop();
            currentSum = currentSum*10 + root->val;
            if(root->left==NULL && root->right==NULL) totalSum += currentSum;

            if(root->left) q.push({root->left, currentSum});
            if(root->right) q.push({root->right, currentSum});
        }
        return totalSum;
    }
};
*/



//morris traversal- threaded binary tree
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        TreeNode *cur = root;
        int totalSum=0, currentSum=0, depth=0;
        while(cur != NULL){

            if(cur->left == NULL){ // left side is not there
                currentSum = currentSum * 10 + cur->val; // preorder(cur->val)
                if(cur->right == NULL) totalSum += currentSum;
                cur = cur->right;
            }
            else{ // left side is there (explore it) 
                TreeNode *prev = cur->left;
                depth=1;
                while(prev->right && prev->right!=cur) prev = prev->right, depth++;

                if(prev->right == NULL){ // Root's Left's Rightmost node has no attachments (means first time visit)
                    prev->right = cur;
                    currentSum = currentSum * 10 + cur->val; // preorder(cur->val)
                    cur = cur->left;
                }else{ // Root's Left's Rightmost node has threaded attachments (means Root's Left Visited already)
                    prev->right = NULL;
                    if(prev->left == NULL) totalSum += currentSum; // that node is being visited last time
                    currentSum = currentSum/pow(10, depth);
                    cur = cur->right;
                }
            }
        }
        return totalSum;
    }
};
