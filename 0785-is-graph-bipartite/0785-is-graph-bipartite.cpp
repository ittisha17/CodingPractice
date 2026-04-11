class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<bool> vis(n,false);
        vector<bool> col(n);
        //let two sets be -1 /-2
        for(int i=0;i<n;i++)
        {
           if(!vis[i])
           {
                 queue<int> q;
                 q.push(i);
                 col[i]=0;
                 vis[i]=true;
                 while(!q.empty())
                 {  
                    int u=q.front();
                    q.pop();
                    for(auto v:graph[u])
                    {
                        if(!vis[v])
                         {q.push(v);
                          col[v]=col[u]^1;
                          vis[v]=true;
                         }
                        else //if already visited
                        {
                            if(col[u]==col[v])
                             return false;
                        }
                    }
                 }

           }   
        }
        return true;
    }
};