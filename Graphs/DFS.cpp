class Solution {
  public:
      vector<int> ans;
     
    void solve(int node,vector<int>&visited,vector<int>adj[])
    {
        visited[node]=1; 
        
        ans.push_back(node);
        
        
        for(auto i:adj[node]){
            if(!visited[i]){
                solve(i,visited,adj);
            }
        }
        
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> visited(V,0);
        solve(0,visited,adj);
        return ans;
    }
};
