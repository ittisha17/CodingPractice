class Solution {
public:
    int maxArea(vector<int>& height) {
        int mxar=0;
        int n=height.size();
        int i=0;
        int j=n-1;
        while(i<j)
        {
            if(height[j]>=height[i])
            {
                mxar=max(mxar,(j-i)*height[i]);
                j=n-1;
                i++;
            }
            else
             {
                mxar=max(mxar,(j-i)*height[j]);
                j--;
             }
            
        }
        return mxar;
    }
};