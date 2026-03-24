class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>ps(n);
        vector<int>ns(n);
        ps[0]=-1;
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
             st.pop();
            if(st.empty())
             ps[i]=-1;
            else
             ps[i]=st.top();
            st.push(i);
        }
        
        stack<int>st2;
        ns[n-1]=n;
        st2.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st2.empty() && arr[st2.top()]>=arr[i])
             st2.pop();
            if(!st2.empty())
             ns[i]=st2.top();
            else
             ns[i]=n;
            st2.push(i);
        }

        long long ans=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            ans=(ans%mod+(1LL*arr[i]*(i-ps[i])*(ns[i]-i))%mod)%mod;
        }
        return ans;

    }
};