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
    int widthOfBinaryTree(TreeNode* root) {
        
       /* if(!root){
            return 0;
        }
        // marking each node as 1,2,3..as starting node is 0 using formula base i=0
        //left child =2i+1;   right child= 2i+2;
        int ans=0;
        queue<pair<TreeNode*,int>> q;           //pair of (nodes,index of that node)
        q.push({root,0});

       
        while(!q.empty()){
            int size=q.size();
             int first,last;
             int mmin=q.front().second; 
             //as to subtract the node of index i.e at each level subtracting first node of that level from others

             for(int i=0;i<size;i++){
                 int curr_index=q.front().second - mmin; //temporary changing values of index
                 TreeNode* node=q.front().first;
                 q.pop();

                 if(i==0) first=curr_index;       //storing first node in that level
                 if(i==size-1) last=curr_index; //storing last node in that level
                 if(node->left) q.push({node->left,curr_index*2+1});
                 if(node->right) q.push({node->right,curr_index*2+2});
             }
             ans=max(ans,last-first+1);

        }
        return ans;
    }*/
     if(!root)
            return 0;
        int ans=0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second;    // to take the id starting from zero
            int first, last;
            for(int i=0; i<size; i++){
                long long cur_id = q.front().second-mmin;         //correction long long
                TreeNode * node = q.front().first;
                q.pop();
                if(i==0) first = cur_id;
                if(i==size-1) last = cur_id;
                if(node->left)
                    q.push({node->left, cur_id*2+1});
                if(node->right)
                    q.push({node->right, cur_id*2+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
        
    }
};
