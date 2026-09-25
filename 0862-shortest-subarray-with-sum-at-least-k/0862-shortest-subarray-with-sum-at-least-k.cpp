class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ln=INT_MAX;
        int sum=0;
        int st=0;
        vector<long long> prefix(n+1,0);
       // prefix[0]=nums[0];
        for(int i=0;i<n;i++)
         prefix[i+1]=nums[i]+prefix[i];
        deque<int> dq;

        for(int i=0;i<=n;i++)
        {
           while(!dq.empty() && prefix[i]-prefix[dq.front()]>=k)
            {
                ln=min(ln,i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefix[i]<=prefix[dq.back()])
             dq.pop_back();
            dq.push_back(i);
        }
        return ln==INT_MAX?-1:ln;
    }
};