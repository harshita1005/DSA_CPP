class Solution {
  public:
    bool dfs(vector<int> adj[], int V, int node,int parent,vector<bool> &visited){
        
      
        queue<int>q;
        q.push(node);
        visited[node]=true;
         
        while(!q.empty()){
            
            int front=q.front();
            q.pop();
            
            for(int v: adj[front]){
                if(!visited[v]){
                    bool ans=dfs(adj,V,v,front,visited);
                    if(ans==true){
                        return true;
                    }
                }
                else if(v != parent && visited[v]==true){
                    return true;
                }
            }
        }
        return false;
    }
   
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(adj,V,i,-1,visited)){
                return true;
                
            }
        }
        return false;
    }
};
