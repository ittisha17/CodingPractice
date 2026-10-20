
bool isdigit(char ch)
{
    return (ch>='0' && ch<='9');
}
class Solution {
public:
    int myAtoi(string s) {
        long long num=0;
        int n=s.length();
        int sign=1;
        int mx=INT_MAX;
        int mn=INT_MIN;
        bool digenc=false;
        bool whitespace=false;
        for(int i=0;i<n;i++)
        {   
            if(isdigit(s[i]))
            { num=1LL*num*10+(s[i]-'0');
              digenc=true;
             }
            else if(s[i]=='-' || s[i]=='+')
             {
                if(digenc || i<n-1 && !isdigit(s[i+1]))
                 break;
                else if(s[i]=='-')
                  sign=-1;
             }
            else if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]=='.')
             break;
            else if (s[i]==' ' && digenc)
             break;
            
            if(num>mx)
             {
                if(sign==-1)
                 return mn;
                else
                 return mx; 
             }

             
        }
        return (int)(sign*num);

    }
};