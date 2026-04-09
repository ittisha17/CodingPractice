

void dfs(int u,vector<bool>&visited,vector<vector<int>>&adj,vector<int>&temp)
{
    visited[u]=true;
    temp.push_back(u);
    for( int v:adj[u]) //for every adjacent node
    {
        if(!visited[v])
         dfs(v,visited,adj,temp);
    }
}



class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
    int n=V;
    int m=edges.size();
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n,false);
    vector<vector<int>> res;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {  
           vector<int>temp;
           dfs(i,visited,adj,temp);
           res.push_back(temp);
        }
    }
    return res;
    }
};
