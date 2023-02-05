/*
 class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
	if(root==NULL)
		return ans;
        
	queue<TreeNode*> q;
	q.push(root);
	TreeNode* temp;
	int cnt = 1;
	while(!q.empty()) {
		int n = q.size();
		vector<int> v;
		while(n--) {
			temp = q.front();
			q.pop();
			v.push_back(temp->val);
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}
		if(cnt%2 == 0)
			reverse(v.begin(), v.end());
		ans.push_back(v);
		v.clear();
		cnt++;
	}
	return ans;
    }
};
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;
        queue<TreeNode*> q;
        if(root==NULL){
            return result;
        }
        q.push(root);
        bool leftToRight=true;        //L-R=true and R-L=false

        while(!q.empty()){

            int size=q.size();
            vector<int>ans(size);

            for(int i =0; i<size ;i++){
                TreeNode* node=q.front();
                q.pop();

                //finding position to insert either reverse or not
                int index= leftToRight ? i : size-1-i;

                ans[index]=node->val;

                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }

            //completing a level
            leftToRight=!leftToRight;
            result.push_back(ans);
        }
        return result;

        
    }
};
