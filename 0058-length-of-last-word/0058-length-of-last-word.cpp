class Solution {
public:
    int lengthOfLastWord(string s) {
        int end=s.length()-1;
        int st;
        while(end>=0 && s[end]==' ')
         end--;
        st=end;
        while(st>=0 && s[st]!=' ')
         st--;
        return(end-st);
    }
};