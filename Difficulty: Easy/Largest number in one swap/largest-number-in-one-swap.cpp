class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n=s.length();
        vector<int> Rmax(n);
        Rmax[n-1]=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]>s[Rmax[i+1]])
             Rmax[i]=i;
            else
             Rmax[i]=Rmax[i+1];
             
        }
        for(int i=0;i<n;i++)
        {
            if(s[Rmax[i]]!=s[i])
             {swap(s[i],s[Rmax[i]]);
             break;}
        }
        return s;
    }
};