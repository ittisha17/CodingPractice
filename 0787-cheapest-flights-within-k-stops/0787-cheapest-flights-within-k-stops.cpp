
struct myCmp
{
    bool operator()(pair<int,pair<int,int>>&p1,pair<int,pair<int,int>>&p2)
    {
        return p1.first>p2.first;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //int n=flights.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int time=flights[i][2];
            adj[u].push_back({time,v});
        }
        
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
         dist[src][0]=0;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,myCmp> pq; //dist and node and stops

        pq.push({0,{src,0}});
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            int d=p.first;
            int u=p.second.first;
            int stop=p.second.second;
            if(stop>k) continue;
            if(dist[u][stop]<d) continue; //older node

            for(auto V:adj[u])
            {  
               if(stop<=k+1 && dist[V.second][stop+1]>d+V.first)
                {
                    dist[V.second][stop+1]=d+V.first;
                    pq.push({d+V.first,{V.second,stop+1}});
                }
            }
        }
        
        int mn=INT_MAX;
        for(int i=0;i<=k+1;i++)
        {
          mn=min(mn,dist[dst][i]);
        }
      return mn==INT_MAX?-1:mn;

    }
};