bool check(int x ,int y,int id, vector<vector<bool>>&visited,vector<vector<char>> &mat, string &word,int ln,int n,int m,vector<int> &dx,vector<int>&dy)
{   
    if(mat[x][y]!=word[id]) return false;
    if(id==ln-1)
     return true;
   
    visited[x][y]=true;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<n &&ny<m  &&!visited[nx][ny])
             if(check(nx,ny,id+1,visited,mat,word,ln,n,m,dx,dy)) 
              return true;
        }
        
    visited[x][y]=false;
    return false;
    
    
    
}


class Solution {
  public:
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        int id=0;
        int ln=word.length();
        int n=mat.size();
        int m=mat[0].size();
         vector<int>dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vector<vector<bool>>visited(n,vector<bool>(m,false));
                if(mat[i][j]==word[0])
                 {if(check(i,j,id,visited,mat,word,ln,n,m,dx,dy))
                  return true; }  
            }
        }
       return false;
        
        
    }
};