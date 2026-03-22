class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int n=s.length();
        int ln=0;
        int st=0;
        int mx_freq=INT_MIN;
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'A']++;
            mx_freq=max(mx_freq,freq[s[i]-'A']);
            while((i-st+1)-mx_freq>k)
            {
               freq[s[st]-'A']--;
               st++;
            }
            ln=max(ln,i-st+1);

        }
        return ln;
    }
};