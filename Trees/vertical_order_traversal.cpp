class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        //will traverse the nodes level wise and using horizontal distance
        //using map will store the horizontal distance for each node
        //queue will traverse each node level wise

        queue<pair<TreeNode*, pair<int,int>>> q;      //pair of( levelwisenode, (H.D,level))
        map<int, map<int,multiset<int>>> nodes;         //pair of(H.D, (level,list of nodes))
        vector<vector<int>> ans;
       if(root==NULL){
           return ans;
       }
       q.push(make_pair(root,make_pair(0,0)));

        while(!q.empty()){

            pair<TreeNode*, pair<int,int>> temp=q.front();
            q.pop();

            TreeNode* frontnode= temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;

            nodes[hd][lvl].insert(frontnode->val);  //storing the hd and lvl value of corresponding node

            if(frontnode->left!=NULL){
                q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
            }
            if(frontnode->right!=NULL){
                q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
            }
        }
        //storing the values in ans vector
        for(auto i: nodes){
            vector<int>res;
            for(auto j: i.second){
                res.insert(res.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(res);
        
            }
     
        
        return ans;


        }
    
};
