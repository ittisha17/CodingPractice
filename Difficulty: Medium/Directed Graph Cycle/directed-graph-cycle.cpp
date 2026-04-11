
bool dfs(int u,vector<bool>&visited,vector<vector<int>>&adj,int V,set<int>&rec_st)
{
    visited[u]=true;
    rec_st.insert(u);
    for(int v:adj[u])
    {
        if(!visited[v])
         {if(dfs(v,visited,adj,V,rec_st))
          return true;
         }
        else //already visited check if its in the same recursion stack
        {if(rec_st.find(v)!=rec_st.end())
          return true;
        }
        
    }
    rec_st.erase(u);
   return false;
    
    
}


class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
         
       
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {  set<int>rec_st;
               
                if(dfs(i,visited,adj,V,rec_st))
                 return true;
            }
        }
        return false;
    }
};