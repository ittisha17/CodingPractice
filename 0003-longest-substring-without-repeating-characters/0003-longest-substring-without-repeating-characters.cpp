class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,0);
        int n=s.length();
        int st=0;
        int i=0;
        int ln=0;
        while(i<n)
        {   
            char ch=s[i];
            if(freq[ch]!=0) //already occured
            {
                while(st<i && freq[ch]!=0 )
                {
                    freq[s[st]]=max(freq[s[st]]-1,0);
                    st++;
                }
            }
            freq[ch]++;
            ln=max(i-st+1,ln);
            i++;
        }
        return ln;
    }
};