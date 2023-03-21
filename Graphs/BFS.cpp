
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code hereclass Solution {
 
        vector<int>res;
       vector<bool>visited(V);
       
       for(int i=0;i<V;i++)
       {
           visited[i]=false;
       }
       
       queue<int>q;
       int s=0;
       q.push(s);
       visited[s]=true;
       while(!q.empty())
       {
           int u=q.front();
           q.pop();
           res.push_back(u);
           for(int v:adj[u])
           {
               if(visited[v]==false)
               {
                   visited[v]=true;
                   q.push(v);
               }
           }
       }
       return res;
    }

};

