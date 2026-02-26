class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int idx=-1;
        int l=0;
        int r=arr.size()-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(arr[mid]==target)
            {
                idx=mid;
                r=mid-1;
            }
            else if(arr[mid]<target)
             l=mid+1;
            else
             { idx=mid;
               r=mid-1;
             }
        }
        if(target>arr[arr.size()-1])
         return arr.size();
        return idx;
    }
};
