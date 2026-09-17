bool isPossible(char dig,int x,int y,vector<vector<char>>&board)
{
   for(int i=0;i<9;i++)
   {
     if(board[x][i]==dig || board[i][y]==dig)
      return false;
   }
   //checking the sub square
   int grid_x=(x/3)*3;
   int grid_y=(y/3)*3;

   for(int i=grid_x;i<grid_x+3;i++)
   {
     for(int j=grid_y;j<grid_y+3;j++)
     {
        if(board[i][j]==dig)
         return false;
     }
   }
   return true;

}

bool solve(int x,int y,vector<vector<char>>&board)
{
    if(x==9) return  true;
    int nx=x;
    int ny=y+1;
    if(ny==9)
    { nx++;
      ny=0;
    }

    if(board[x][y]!='.') 
     return solve(nx,ny,board);
    
    else //if empty
    {
        for(char dig='1';dig<='9';dig++)
        {
            if(isPossible(dig,x,y,board))
            {
                board[x][y]=dig;
                if(solve(nx,ny,board)) return true;
                board[x][y]='.';
            }
        }
    }
    return false; 

}

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
       int m=9;
        solve(0,0,board);
    }
};