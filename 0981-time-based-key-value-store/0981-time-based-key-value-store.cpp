bool myCmp(pair<int,string> &p1,pair<int,string>&p2)
{
    if(p1.first!=p2.first)
     return p1.first<p2.first;
    else
     return p1.second<p2.second;
}

string Bsearch(vector<pair<int,string>> &vec,int x)
{
    int l=0;
    int h=vec.size()-1;
    string ans="";
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(vec[mid].first<=x)
        { ans=vec[mid].second;
          l=mid+1;
        }
        else //if(vec[mid].first>x)
         h=mid-1;
    }
    return ans;
}

class TimeMap {
public:
     unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
         //sort(mp[key].begin(),mp[key].end(),myCmp);
       string val= Bsearch(mp[key],timestamp);
       return val;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */