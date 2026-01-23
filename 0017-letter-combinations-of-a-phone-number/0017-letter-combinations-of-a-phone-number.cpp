void solve(int id,unordered_map<char,string>&mp,string digits,vector<string> &res,string curr)
{
   if(id==digits.length())
    {res.push_back(curr);
     return;
    }
   for(int i=0;i<mp[digits[id]].length();i++)
   {
     curr+=mp[digits[id]][i];
     solve(id+1,mp,digits,res,curr);
     curr.pop_back();
   }
   return;
}


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        int id=0; //index of given string;
        vector<string> res;
        string curr="";
        solve(0,mp,digits,res,curr);
        return res;
    }
};