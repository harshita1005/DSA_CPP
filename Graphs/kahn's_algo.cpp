
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    //find out indegree
	    vector<int> indegree(V, 0);
	    
	    for(int i=0; i<V; i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    vector<int> ans;
	    
	    queue<int> q;
	    
	   
	    
	    //0 wale indegree ko push krdo
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int a = q.front();
	        q.pop();
	        ans.push_back(a);
	        
	        for(auto it: adj[a]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    
	    return ans;
	}
};
