class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> freq(26);

       int mx_freq=0;
       for(int i=0;i<tasks.size();i++)
       {
         freq[tasks[i]-'A']++;
         mx_freq=max(mx_freq,freq[tasks[i]-'A']);
       }
       int cnt_mx=0;
       for(int i=0;i<26;i++)
       {
        if(freq[i]==mx_freq)
         cnt_mx++;
       }

       int ln=tasks.size();
       int ans=max(ln,(mx_freq-1)*(n+1)+cnt_mx);
       return ans;
    }
};