void bfs(vector<vector<int>>& heights,int n,int m, vector<vector<bool>> &visited,queue<pair<int,int>>&q)
{
    vector<int> dx={0,0,1,-1};
    vector<int>dy={1,-1,0,0};
   while(!q.empty())
   {
     auto p=q.front();
     q.pop();
     int x=p.first;
     int y=p.second;
     for(int i=0;i<4;i++)
     {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && heights[nx][ny]>=heights[x][y])
        {
            q.push({nx,ny});
            visited[nx][ny]=true;
        }
     }
     
   }
}


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pacific_visited(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic_visited(n,vector<bool>(m,false));

        queue<pair<int,int>> pacific_q;
        queue<pair<int,int>> atlantic_q;

        for(int i=0;i<n;i++)
        { pacific_q.push({i,0}); //pacific ocean first col
          pacific_visited[i][0]=true;
          atlantic_q.push({i,m-1}); //atlantic last column
          atlantic_visited[i][m-1]=true;
        }

        for(int i=1;i<m;i++)
         {pacific_q.push({0,i});  //pacific ocean all columns first row
          pacific_visited[0][i]=true;
         }
        for(int i=0;i<m-1;i++)
         {atlantic_q.push({n-1,i}); //bottom row all columns
          atlantic_visited[n-1][i]=true;
         }


        bfs(heights,n,m,pacific_visited,pacific_q);
        bfs(heights,n,m,atlantic_visited,atlantic_q);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific_visited[i][j] && atlantic_visited[i][j])
                 res.push_back({i,j});
            }
        }
        return res;
    }
};