class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> mp;
        vector<string> words;
        int st=0;
        int i=0;
        int m=pattern.length();
        int n=s.length();
        while(i<n)
        {
            if(s[i]==' ')
             {
                words.push_back(s.substr(st,i-st));
                st=i+1;
             }
             i++;
        }
       
        words.push_back(s.substr(st));
        if(m!=words.size()) return false;  //no. owrds should be equal to characters in pattern
        set<string> s1(words.begin(),words.end());

        set<char> s2(pattern.begin(),pattern.end());
        if(s2.size()!=s1.size()) return false;
        for(int i=0;i<m;i++)
        {
            if(mp.find(pattern[i])!=mp.end())
            {
                if(mp[pattern[i]]!=words[i]) return false;
            }
            else
             mp[pattern[i]]=words[i];
        }
        return true;
    }
};