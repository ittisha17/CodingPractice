void prev_sm(vector<int>&nums,vector<int>&ps)
{
    stack<int> st;
    int n=nums.size();
    st.push(0);
    ps[0]=-1;
    for(int i=1;i<n;i++)
    {
      while(!st.empty() && nums[i]<=nums[st.top()])
       st.pop();
      if(st.empty())
       ps[i]=-1;
      else
       ps[i]=st.top();
      st.push(i);
    }
}

void next_sm(vector<int>&nums,vector<int>&ns)
{
    stack<int> st;
    int n=nums.size();
    st.push(n-1);
    ns[n-1]=n;
    for(int i=n-2;i>=0;i--)
    {
      while(!st.empty() && nums[i]<=nums[st.top()])
       st.pop();
      if(st.empty())
       ns[i]=n;
      else
       ns[i]=st.top();
      st.push(i);
    }
}


class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int mod=1e9+7;
        int n=nums.size();
        vector<long long> pre_sum(n);
        vector<int> pre_sm(n);
        vector<int> nex_sm(n);

        prev_sm(nums,pre_sm);
        next_sm(nums,nex_sm);

        pre_sum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pre_sum[i]=nums[i]+pre_sum[i-1];
        }


        long long ans=0;
        for(int i=0;i<n;i++)  //calculating max min prod for every elemnt
        {
           long long  elem=nums[i];
           int r=nex_sm[i]-1;
           int l=pre_sm[i]+1;
           long long  sum=pre_sum[r]- (l>0? pre_sum[l-1]:0);
           long long val=(elem*sum);
           ans=max(ans,val);
        }
        return ans%mod;
    }
};