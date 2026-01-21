class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n=arr.size();
        vector<int> res(n);
        res[0]=1;
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++)
        {   
          while(!st.empty()&& arr[i]>=arr[st.top()])
            st.pop();
          if(st.empty())
           res[i]=i+1;
          else
           res[i]=i-st.top();
            st.push(i);
        }
        return res;
    }
};