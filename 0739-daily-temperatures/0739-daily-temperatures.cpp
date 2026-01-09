class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        int n=temp.size();
        vector<int> res(n);
        res[n-1]=0;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && temp[st.top()]<=temp[i])
             st.pop();
            if(st.empty())
             res[i]=0;
            else
             res[i]=st.top()-i;
            st.push(i);
        }
        return res;
    }
};