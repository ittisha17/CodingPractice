
bool dfs(int u,vector<bool>&visited,vector<vector<int>>&adj,int cnt,int n)
{   
    if(cnt==n) 
     return true;
    visited[u]=true;
    for(int v:adj[u])
    {
        if(!visited[v])
         if(dfs(v,visited,adj,cnt+1,n))
          return true;;
    }
    visited[u]=false;
    return false;
    
}
class Solution {
  public:
    bool check(int n, int m, vector<vector<int>> edges) {
        // code here
        
        vector<vector<int>> adj(n+1);
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n+1,false);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(dfs(i,visited,adj,1,n))
             return true;
        }
       return false;
        
    
    }
};
