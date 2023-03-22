class Solution {
  public:
  
    bool bfs(vector<int>adj[],int V, int node, vector<bool> &visited){
        
        vector<int>parent(V,-1);
        queue<int>q;
        
        q.push(node);
        visited[node]=true;
        
        while(!q.empty()){
            
            int front=q.front();
            q.pop();
            
            for(int v: adj[front]){
                
                if(visited[v]==true && v != parent[front]){         //cycle detected
                    return true;
                }
                if(!visited[v]){
                q.push(v);
                visited[v]=true;
                parent[v]=front;
            }
          }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        bool ans;
        
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                ans=bfs(adj,V,i,visited);
            }
            if(ans==true){
                return true;
        }
        }
        return  false;
        
        
    }
};
