class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        
        for(int i=0;i<m;i++)
        {  
            string curr="";
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==n-1)
                 curr+=".";
                else
                 curr+="#";
            }
            res.push_back(curr);
        }
        return res;

    }
};