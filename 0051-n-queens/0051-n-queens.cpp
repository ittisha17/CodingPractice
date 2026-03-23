
bool isPoss(int r,int c,vector<string>&temp,int n)
{
    //as going column vise so dontneed to check columns
    for(int i=0;i<=c;i++)
     if(temp[r][i]=='Q')    //same row
      return false;
    int row=r;
    int col=c;
    while(row>=0 && col>=0)    //upper left diagonal
     {
        if(temp[row][col]=='Q')
         return false;
        row--;
        col--;
     }
     row=r;
     col=c;
    while(row<n && col>=0)
    {
        if(temp[row][col]=='Q')        //lower left diagonal
         return false;
        row++;
        col--;
    }
    return true;
}


void solve(int c,int n,vector<vector<string>>&res,vector<string>&temp)
{
    if(c==n)
    { res.push_back(temp);
     return;}
    
    string curr="";
    for(int r=0;r<n;r++)
    {
        if(isPoss(r,c,temp,n))
         {temp[r][c]='Q';
          solve(c+1,n,res,temp);
          temp[r][c]='.';
         }
    }
     
     
}


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s="";
        for(int i=0;i<n;i++)
         s+=".";
        vector<string>temp(n,s);
        solve(0,n,res,temp);
        return res;

    }
};