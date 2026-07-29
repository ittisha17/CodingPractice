class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        set<int> st;
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
             if(st.find(arr[i]+1)!=st.end() && st.find(arr[i]-1)!=st.end())
              cnt--;
             else if(st.find(arr[i]+1)!=st.end() || st.find(arr[i]-1)!=st.end())
             cnt+=0;
             else
              cnt++;
             st.insert(arr[i]);
        }
        return cnt;
    }
};
