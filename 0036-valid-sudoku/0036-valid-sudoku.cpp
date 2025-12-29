class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        for(int i=0;i<n;i++)  //every row
        {
             vector<int>freq(10,0);
             for(int j=0;j<n;j++)
             {
                if(board[i][j]>='0' && board[i][j]<='9')
                { freq[board[i][j]-'0']++;
                  if(freq[board[i][j]-'0']>1) return false;
                }
             }
        }
        for(int j=0;j<n;j++)  //every column
        {   
            vector<int>freq(10,0);
            for(int i=0;i<n;i++)
            {
                if(board[i][j]>='0' && board[i][j]<='9')
                { freq[board[i][j]-'0']++;
                  if(freq[board[i][j]-'0']>1) return false;
                }
            }
        }

        int row_st=0;
        int col_st=0;
        while(row_st<9)
        {
            while(col_st<9)
            {   
                vector<int>freq(10,0);
                for(int i=row_st;i<row_st+3;i++)
                {
                    for(int j=col_st;j<col_st+3;j++)
                     {  if(board[i][j]>='0' && board[i][j]<='9')
                         { freq[board[i][j]-'0']++;
                              if(freq[board[i][j]-'0']>1) return false; }
                     }
                }
                col_st+=3;
            }
            col_st=0;
            row_st+=3;
        }
        return true;


       

    }
};