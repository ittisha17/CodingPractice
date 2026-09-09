class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>freq_p(26,0);
        vector<int>freq_s(26,0);
        int k=p.length();
        if(p.length()>s.length()) return {};
        vector<int>res;
        for(int i=0;i<k;i++)
        {
            freq_p[p[i]-'a']++;
             freq_s[s[i]-'a']++;
        }

        if(freq_p==freq_s)
         res.push_back(0);

        for(int i=k;i<s.length();i++)
        {  freq_s[s[i]-'a']++;
           freq_s[s[i-k]-'a']--;
           
           if(freq_s==freq_p)
            res.push_back(i-k+1);
        }
        return res;

    }
};