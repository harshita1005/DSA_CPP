class Solution
{
	public:
	
	void dfs_topo(vector<int> adj[], vector<bool> &visited, stack<int> &s, int node){
	    
	    visited[node]=true;
	    
	    for(auto v : adj[node]){
	        
	        if(!visited[v]){
	            dfs_topo(adj,visited,s,v);
	        }
	    }
	    s.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	
	{
	    vector<bool>visited(V,false);
	    vector<int>ans;
	    stack<int>s;
	    
	    for(int i=0;i<V;i++){
	        
	        if(!visited[i]){
	            dfs_topo(adj,visited,s,i);
	        }
	    }
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	   
	}
};
