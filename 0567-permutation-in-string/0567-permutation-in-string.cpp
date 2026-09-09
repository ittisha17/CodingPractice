

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq_s1(26,0);
        vector<int>freq_s2(26,0);
        int k=s1.length();
        if(s1.length()>s2.length()) return false;
        for(int i=0;i<k;i++)
        {
            freq_s1[s1[i]-'a']++;
             freq_s2[s2[i]-'a']++;
        }

        if(freq_s1==freq_s2)
         return true;

        for(int i=k;i<s2.length();i++)
        {  freq_s2[s2[i]-'a']++;
           freq_s2[s2[i-k]-'a']--;
           
           if(freq_s2==freq_s1)
            return true;
        }
        return false;

    }
};