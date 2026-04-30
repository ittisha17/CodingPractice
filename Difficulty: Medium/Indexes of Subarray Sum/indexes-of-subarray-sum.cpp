class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        vector<int> res;
        int n=arr.size();
        int sum=0;
        int st=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
           
            while(sum>target && st<n)
            {
                sum-=arr[st];
                st++;
            }
             if(sum==target)
            {
                res.push_back(st+1);
                res.push_back(i+1);
                break;
            }
        }
        if(res.size()==0)
         return {-1};
        return res;
        
       
    }
};