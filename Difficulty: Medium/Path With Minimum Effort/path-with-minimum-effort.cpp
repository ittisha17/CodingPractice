
struct myCmp
{  
    bool operator()(pair<int,pair<int,int>>&p1,pair<int,pair<int,int>>&p2)
   { return p1.first>p2.first;
   }
};

class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        
         vector<int> dx={1,-1,0,0};
         vector<int> dy={0,0,1,-1};
        
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,myCmp> pq;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            int d=p.first;
            int x=p.second.first;
            int y=p.second.second;
            if(dist[x][y]<d) continue; //older cell
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m )
                {   
                    int d=max(dist[x][y],abs(mat[x][y]-mat[nx][ny]));
                    if(dist[nx][ny]>d)
                    {   dist[nx][ny]=d;
                        pq.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
            
         }
        return dist[n-1][m-1];
    }
};
