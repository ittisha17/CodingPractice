class Solution {
public:
    bool isPalindrome(string s) {
        string st="";
        for(int i=0;i<s.length();i++)
        {
            if(iswalnum(s[i]))
            {
                if(s[i]>='A' && s[i]<='Z')
                 st+=s[i]+32;
                else
                 st+=s[i];
            }
        }
        int n=st.length();
        int i=0;
        int j=n-1;
        while(i<=j)
        {
            if(st[i]==st[j])
            {
                i++;
                j--;
            }
            else
             return false;
        }
        return true;
    }
};