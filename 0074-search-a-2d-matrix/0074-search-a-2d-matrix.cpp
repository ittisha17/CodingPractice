class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0;
        int h=(m*n)-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int col=mid%n;
            int row=(mid-col)/n;
            if(matrix[row][col] ==target)
             return true;
            else if(matrix[row][col]>target)
             h=mid-1;
            else
             l=mid+1;
             
        }
        return false;
    }
};