class Solution {
  public:
    bool dfs(vector<int> adj[], int node, vector<bool> &visited, vector<bool> & dfsvisited){
        
       visited[node]=true;
       dfsvisited[node]=true;
       
       for(int v: adj[node]){
           
           if(!visited[v]){
               
           bool res=dfs(adj,v,visited,dfsvisited);
           
           if(res==true){
            return true;
       }
           }
           
           else if(visited[v]==true && dfsvisited[v]==true){    //cycle detected
               return true;
           }
        
    }
    dfsvisited[node]=false;
    return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool>visited(V,false);
        vector<bool>dfsvisited(V,false);
        
        for(int i=0;i<V;i++){
            
            if(!visited[i]){
                bool ans=dfs(adj,i,visited,dfsvisited);
            
            if(ans==true){
                return true;
            }
        }
        }
     return false;
    }
};
