
int t=0;

void dfs(int u,int parent,vector<int>&low,vector<int>&disc,vector<bool>&visited,vector<vector<int>>&res,vector<vector<int>>&adj)
{   
    visited[u]=true;
    disc[u]=low[u]=++t;
    for(int v:adj[u])
    {
        if(v==parent)
         continue;
        else if(visited[v])
         low[u]=min(low[u],disc[v]);
        else
         {dfs(v,u,low,disc,visited,res,adj);
         low[u]=min(low[u],low[v]);
         if(low[v]>disc[u])
          res.push_back({u,v});
         }
         
    }

}

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> res;
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++)
        { int u=connections[i][0];
          int v=connections[i][1];
          adj[u].push_back(v);
          adj[v].push_back(u);
        }

        vector<bool>visited(n,false);
        vector<int>low(n);
        vector<int>disc(n);
        low[0]=0;
        dfs(0,-1,low,disc,visited,res,adj);
        return res;
    }
};