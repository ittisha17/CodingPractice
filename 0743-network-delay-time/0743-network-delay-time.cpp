class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }

        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k}); //dist and node
        while(!pq.empty())
        {
            auto p=pq.top();
            int u=p.second;
            int d=p.first;
            pq.pop();
            if(d>dist[u]) continue;
            for(auto pv:adj[u])
            {
                int v=pv.first;
                int w=pv.second;
                if(dist[u]+w<dist[v])
                 {
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                 }
            }
        }

        int res=0;
        for(int i=1;i<=n;i++)
        {
          if(dist[i]==INT_MAX)
           return -1;
          res=max(res,dist[i]);
        }
        return res;
    }
};