class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<pre.size();i++)
        {
            int a=pre[i][0];
            int b=pre[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        vector<bool> vis(n,false);
       
        vector<int> res;
         queue<int>q;
         for(int i=0;i<n;i++)
         {
            if(indegree[i]==0)
             {q.push(i);
             }
         }
         while(!q.empty())
         {
            int u=q.front();
            q.pop();
            if(indegree[u]==0)
             res.push_back(u);
            for(int v:adj[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                   q.push(v);
            }
         }
         if(res.size()!=n) return {};
         return res;




        

    }
};