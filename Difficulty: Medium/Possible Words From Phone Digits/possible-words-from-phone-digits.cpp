


void Solve(int id,vector<string>&res,string &curr,vector<int>&arr,int n,unordered_map<int,string> &mp)
{    
    
    if(id==n)
    {
        res.push_back(curr);
        return;
    }
    
    if(arr[id]==1 ||arr[id]==0)
      Solve(id+1,res,curr,arr,n,mp);
    else
    {string s=mp[arr[id]];
    for(int i=0;i<s.length();i++)
    { 
        curr+=s[i];
        Solve(id+1,res,curr,arr,n,mp);
        curr.pop_back();
    }
    }
    
}


class Solution {
  public:
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        unordered_map<int,string> mp;
        mp[0]="";
        mp[1]="";
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        
        int idx=0;
        string curr="";
        vector<string> res;
        int n=arr.size();
        Solve(0,res,curr,arr,n,mp);
        return res;
        
    
    }
};