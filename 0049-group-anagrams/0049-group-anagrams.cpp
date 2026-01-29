class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> mp;
        for(string s:strs)
        {
            string key=s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);

        }
        for(auto p:mp)
        {
            res.push_back(p.second);
        }
        return res;
    }
};