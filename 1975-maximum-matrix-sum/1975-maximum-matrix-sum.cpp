class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int cnt_neg=0;
        int smll=INT_MAX;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                smll=min(smll,abs(matrix[i][j]));
                ans+=abs(matrix[i][j]);
                if(matrix[i][j]<0)
                 cnt_neg++;
            }
        }
        if(cnt_neg%2==0)
         return ans;
        else
        {
            ans=ans-2*smll;
            return ans;
        }
         
    }
};