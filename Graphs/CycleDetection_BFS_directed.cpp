class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
       
         int indegree[v]={0};

        for(int i=0;i<v;i++){

            for(auto it:adj[i]){

                indegree[it]++;
            }
        }

        queue<int>q;

        vector<int>topo;

        for(int i=0;i<v;i++){

            if(indegree[i]==0){

                q.push(i);

            }

        }

        while(!q.empty()){

            int node=q.front();

            q.pop();

            topo.push_back(node);

            for(auto it: adj[node]){

                indegree[it]--;

                if(indegree[it]==0)q.push(it);

            }

        }

        if(topo.size()==v)return false;

        return true;

    }
};
