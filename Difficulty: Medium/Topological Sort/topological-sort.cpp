class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> res;
        vector<int>indegree(V,0);
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
             q.push(i);
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
             res.push_back(u);
            for(int v:adj[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                 q.push(v);
            }
            
        }
        return res;
        
    }
};