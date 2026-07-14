

class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        // code here
        if(arr.size()==0)
         return n*m;
        vector<int> row;
        vector<int> col;
        for(int i=0;i<arr.size();i++)
        {
            int r=arr[i][0];
            int c=arr[i][1];
            row.push_back(r);
            col.push_back(c);
        }
        
        sort(row.begin(),row.end());
        sort(col.begin(),col.end());
        
        vector<int> poss_ln;
        vector<int> poss_breadth;
        
        poss_ln.push_back(row[0]-1);
        poss_breadth.push_back(col[0]-1);
        
        for(int i=1;i<row.size();i++)
        {
            int l=row[i]-row[i-1]-1;
            poss_ln.push_back(l);
            
            int b=col[i]-col[i-1]-1;
            poss_breadth.push_back(b);
        }
        
        poss_ln.push_back(n-row[row.size()-1]);
        poss_breadth.push_back(m-col[col.size()-1]);
        
        sort(poss_ln.begin(),poss_ln.end());
        sort(poss_breadth.begin(),poss_breadth.end());
        
        int ans=poss_ln[poss_ln.size()-1]*poss_breadth[poss_breadth.size()-1];
        return ans;
        
        
    }
};