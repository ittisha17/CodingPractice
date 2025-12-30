class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int>st;
        map<int,int> freq;
        for(int i=0;i<arr.size();i++)
          freq[arr[i]]++;
        for(auto p:freq)
        {
            if(st.find(p.second)!=st.end())
             return false;
            st.insert(p.second);
        }
        return true;
    }
};