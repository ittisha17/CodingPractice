
void dfs(int u,vector<vector<int>> &adj,vector<bool>&vis)
{
    vis[u]=true;
    for(int v:adj[u])
    {
        if(!vis[v])
         dfs(v,adj,vis);
    }
}


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int no_edges=connections.size();
        if(no_edges<n-1)
         return -1;
        vector<vector<int>> adj(n);
       int src;
        for(int i=0;i<connections.size();i++)
        {   
            int u=connections[i][0];
            int v=connections[i][1];
            src=u;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //no. of min operations is basically no. of disconnected components
        vector<bool> vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if( !vis[i])
             { dfs(i,adj,vis);
              cnt++;
             }
        
        }
        return cnt-1;

        

    }
};