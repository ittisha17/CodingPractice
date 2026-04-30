


void sort(vector<char>&character,map<char,int>&mp)
{
    int n=character.size();
    vector<pair<int,char>> vec;
    for(int i=0;i<n;i++)
    {
        vec.push_back({mp[character[i]],character[i]});
    }
    sort(vec.begin(),vec.end());
    
    for(int i=0;i<n;i++)
    {
        //cout<<vec[i].first<<vec[i].second<<endl;
        character[i]=vec[i].second;
    }
}

class Solution {
  public:
    void matchPairs(vector<char> &nuts, vector<char> &bolts) {
        // code here
        map<char,int> mp;
        mp['!']=1;
        mp['#']=2;
        mp['$']=3;
        mp['%']=4;
        mp['&']=5;
        mp['*']=6;
        mp['?']=7;
        mp['@']=8;
        mp['^']=9;
        
        sort(nuts,mp);
        sort(bolts,mp);
    }
};