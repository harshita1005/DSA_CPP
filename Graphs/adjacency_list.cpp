class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
       
       
       vector<vector<int>> newAdj;
        for(int i=0;i<V;i++)
{
    vector<int>row; 
    row.push_back(i);
    for(auto it:adj[i])
        row.push_back(it);
    
    newAdj.push_back(row);
}
return newAdj;
        
    }
};
