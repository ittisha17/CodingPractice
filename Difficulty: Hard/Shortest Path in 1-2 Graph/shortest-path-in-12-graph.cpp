
struct myCmp{
    bool operator()(pair<int,int>&p1,pair<int,int>&p2)
    {
        return p1.second>p2.second;
    }
};

class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> dist(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,myCmp> pq;
        
        dist[src]=0;
        pq.push({src,0});
        
        while(!pq.empty())
        {
            auto p=pq.top();
            int u=p.first;
            int d=p.second;
            pq.pop();
            if(d>dist[u])
             continue;
            for(auto pr:adj[u])
            {
                int v=pr.first;
                int w=pr.second;
                if(dist[v]>d+w)
                 {dist[v]=d+w;
                 pq.push({v,dist[v]});
                 }
            }
        }
        if(dist[dest]==INT_MAX)
         return -1;
        else
         return dist[dest];
        
    }
};