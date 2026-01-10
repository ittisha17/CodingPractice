class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m+1,false));
        //checking for bouradary'o's
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O')
                 {
                    visited[i][j]=true;
                    q.push({i,j});
                 }
            }
        }
        while(!q.empty())
        {
            auto u=q.front();
            q.pop();
            int x=u.first;
            int y=u.second;
            vector<int> dx={0,0,1,-1};
            vector<int> dy={1,-1,0,0};
            for(int i=0;i<4;i++)
            {   int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny] && board[nx][ny]=='O')
                {
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
             }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && !visited[i][j])
                  board[i][j]='X';
            }
        }
    }
};