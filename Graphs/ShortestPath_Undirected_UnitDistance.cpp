class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        //N- Number of Node    M-number of edges
        //creating adjanceny list
        vector<int>adj[N];
        for(int i=0;i<M;i++){
             int u=edges[i][0];
             int v=edges[i][1];

             adj[u].push_back(v);
             adj[v].push_back(u);

        }
        
        vector<bool>visited(N,false);
        vector<int>dist(N,INT_MAX);
        queue<int>q;
        q.push(src);
        visited[src]=true;
        dist[src]=0;
        
        while(!q.empty()){
            
            int front=q.front();
            q.pop();
            
            for(auto i:adj[front]){
                
                if(!visited[i]){
                    
                    if(dist[front] + 1 < dist[i]){
                        dist[i]=dist[front]+1;
                        visited[i]=true;
                        q.push(i);
                    
                }
            }
        }
        }
            //create an ans vector to store the unreacable nodes that are marked as -1
            
            vector<int>ans(N,-1);
            for(int i=0;i<N;i++){
                if(dist[i]!=INT_MAX){
                    ans[i]=dist[i];
                }
            }
            return ans;
            
        
    }
};
