class Solution {
public:
    //dfs call
    void dfs(int node,vector<int>&vis,vector<int>adjlist[])
    {
        vis[node]=1; 
        for(auto i:adjlist[node]){
            if(!vis[i]){
                dfs(i,vis,adjlist);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V = isConnected[0].size();
            vector<int> adjlist[V];
          //Converting Adjacency matrix to Adjacency list
          for(int i=0;i<V;i++){
              for(int j=0;j<V;j++){
                  
                  if(isConnected[i][j]==1 && i!=j){
                      adjlist[i].push_back(j);
                      adjlist[j].push_back(i);
                  }
              }
          }

        // traversing nodes and checking the number of components
        vector<int> vis(V,0);
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adjlist);
            }
        }
        return cnt;
    }
};
