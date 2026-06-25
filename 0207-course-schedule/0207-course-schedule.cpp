bool isCycle(int src,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&rec_st)
{
    visited[src]=true;
    rec_st[src]=true;
    for(int v:adj[src])
    {
        if(rec_st[v])
         return true;
        if(!visited[v])
        {
            if(isCycle(v,adj,visited,rec_st))
             return true;
        }
    }
    rec_st[src]=false;
    return false;
}


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(int i=0;i<prereq.size();i++)
        {  
            int v=prereq[i][0];
            int u=prereq[i][1];
            adj[u].push_back(v);
        }

        vector<bool>visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {   vector<bool> rec_st(n,false);
                if(isCycle(i,adj,visited,rec_st))
                 return false;
            }
        }
        return true;
        

    }
};