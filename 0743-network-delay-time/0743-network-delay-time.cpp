
struct myCmp
{
    bool operator()(pair<int,int>&p1,pair<int,int>&p2)
    {
        return p1.second>p2.second;
    }
};

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
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,myCmp> pq;
        pq.push({k,0});  //node and distance
        while(!pq.empty())
        {
            auto p=pq.top();
            int u=p.first;
            int w=p.second;
            pq.pop();
            if(w>dist[u]) continue;
            for(auto V:adj[u])
            {
                int v=V.first;
                int dst=V.second;
                int new_dst=dist[u]+dst;
                if(new_dst<dist[v])
                {
                    dist[v]=new_dst;
                    pq.push({v,dist[v]});
                }
             }
        }
       
       int ans=INT_MIN;
        for(int i=1;i<=n;i++)
          ans=max(ans,dist[i]);
        if(ans==INT_MAX)
          ans=-1;
        return ans;

    }
};