class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        vector<int> res;
        int st=0;
        int i=0;
        int n=arr.size();
        int sum=0;
        while(i<n)
        {
            sum+=arr[i];
            while(sum>target)
            {
                sum-=arr[st];
                st++;
            }
            if(sum==target)
            { res.push_back(st+1);
              res.push_back(i+1);
             return res;
            }
            i++;
            
        }
        if(res.size()==0)
         res.push_back(-1);
        return res;
    }
};