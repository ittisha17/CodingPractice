

bool isCycle(int u,vector<bool>&visited,vector<vector<int>>&adj,vector<bool>&rec_st)
{
    visited[u]=true;
    rec_st[u]=true;
    for(int v:adj[u])
    {
        if(!visited[v])
         {
             if(isCycle(v,visited,adj,rec_st))
              return true;
         }
        else
        {
            if(rec_st[v])
             return true;
        }
    }
    rec_st[u]=false;
    return false;
}


class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // Code here
        vector<vector<int>> adj(n);
        for(int i=0;i<pre.size();i++)
        {
            int v=pre[i][0];
            int u=pre[i][1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            vector<bool>rec_st(n,false);
            if(isCycle(i,visited,adj,rec_st))
             return false;
        }
        return true;
    }
};