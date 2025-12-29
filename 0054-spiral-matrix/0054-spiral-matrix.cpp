class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> res;
        int n=matrix.size();
        int m=matrix[0].size();
        int a=0;
        int d=0;
        int b=m-1;
        int c=n-1;
        while(a<=c && d<=b)
        {
            for(int i=d;i<=b;i++)
             res.push_back(matrix[a][i]);
            a++;
           
            for(int i=a;i<=c;i++)
             res.push_back(matrix[i][b]);
            b--;
           if(a<=c)
           { for(int i=b;i>=d;i--)
             res.push_back(matrix[c][i]);
            c--;
           }
           
           if(b>=d)
           { for(int i=c;i>=a;i--)
             res.push_back(matrix[i][d]);
           }
            d++;
             
        }
        return res;
    }
};