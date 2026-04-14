
struct myCmp
{
    bool operator()(pair<int,pair<int,int>>&p1,pair<int,pair<int,int>>&p2)
    {return p1.first>p2.first;}
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX)); //stores te min effor of every cell

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,myCmp> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        queue<pair<int,int>> q;
        
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            int x=p.second.first;
            int y=p.second.second;
            if(p.first>dist[x][y]) continue; //current distance > imples repeat
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m)  //if valid
                { 
                     int new_dst=max(dist[x][y],abs(heights[x][y]-heights[nx][ny]));
                     if(new_dst<dist[nx][ny])
                     {
                        dist[nx][ny]=new_dst;
                        pq.push({new_dst,{nx,ny}});
                     }
                }
            } 
        }
        return dist[n-1][m-1];


    }
};