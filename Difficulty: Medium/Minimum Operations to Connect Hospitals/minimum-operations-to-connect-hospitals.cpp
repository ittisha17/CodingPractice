

void dfs(int u,vector<vector<int>>&adj,vector<bool>&visited)
{
    visited[u]=true;
    for(int v:adj[u])
    {
        if(!visited[v])
          dfs(v,adj,visited);
    }
    
}


class Solution {
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        int n=edges.size();
        if(n<V-1)
         return -1;
         
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(V,false);
        
        int cnt_connected=-1;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited);
                 cnt_connected++;
            }
        }
        return cnt_connected;
        
    }
};
