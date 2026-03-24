class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> ps(n);
        vector<int> ns(n);
        ps[0]=-1;
        ns[n-1]=n;
        vector<long long> p_sum(n);
        p_sum[0]=nums[0];
        for(int i=1;i<n;i++)
         p_sum[i]=nums[i]+p_sum[i-1];
        
        stack<int> st1;
        st1.push(0);
        for(int i=1;i<n;i++)
        {
            while(!st1.empty() && nums[st1.top()]>nums[i])
             st1.pop();
            if(st1.empty())
             ps[i]=-1;
            else
             ps[i]=st1.top();
            
            st1.push(i);
        }
        stack<int>st2;
        st2.push(n-1);
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() && nums[st2.top()]>=nums[i])
             st2.pop();
            if(st2.empty())
             ns[i]=n;
            else
             ns[i]=st2.top();
            
            st2.push(i);
        }

        long long ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {   
            int l=ps[i]+1;
            int r=ns[i]-1;
           long long total;
          if(l == 0)
            total = p_sum[r];
          else
           total = p_sum[r] - p_sum[l-1];
            long long val=(nums[i]*total);
            ans=max(ans,val);
        }
        return ans%mod;

        

        
        
    }
};