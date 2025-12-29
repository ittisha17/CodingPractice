string rev_word(string&s)
{
      int i=0;
        int j=s.length()-1;
        while(i<=j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
}

class Solution {
public:

    string reverseWords(string s) {
        int i=0;
        int j=s.length()-1;
        int n=s.length();
        while(i<=j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }

        string ans="";
        i=0;
        j=0;
        while(i<n)
        { 
            while(i<n && s[i]==' ')
                i++;   //start
            if(i>=n) break;
            j=i;
            while(j<n && s[j]!=' ')  //marking end
              j++;
            string word=s.substr(i,j-i);
            rev_word(word);
            if(ans.length()==0)
               ans+=word;   //if first word add directly
            else
             ans+=" "+word;  //add space then add other words
            i=j+1;
        }
        return ans;

    }
};