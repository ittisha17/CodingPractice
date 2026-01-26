class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        if(n1!=n2) return false;
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        set<char> s1;
        for(char ch:word1)
         s1.insert(ch);
        for(char ch:word2)
        {
            if(s1.find(ch)==s1.end())   //character of s2 not in s1;
             return false;
        }
        vector<int> l1(26,0);
        vector<int> l2(26,0);
        for(int i=0;i<n1;i++)
        {
            l1[word1[i]-'a']++;
            l2[word2[i]-'a']++;
        }
        sort(l1.begin(),l1.end());
        sort(l2.begin(),l2.end());
        return l1==l2;

    }
};