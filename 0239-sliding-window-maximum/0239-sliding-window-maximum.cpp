class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        multiset<int> st;
        for(int i=0;i<k;i++)
         st.insert(nums[i]);
        int n=nums.size();
        auto mx=st.end();
        mx--;
        res.push_back(*mx);
        for(int i=k;i<n;i++)
        {
            auto it=st.find(nums[i-k]);
            st.erase(it);
            st.insert(nums[i]);
            mx=st.end();
            mx--;
            res.push_back(*mx);

        }
        return res;
    }
};