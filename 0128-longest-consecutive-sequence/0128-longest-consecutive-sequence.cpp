
class DSU{
    public:
    int n;
    vector<int> parent;
    vector<int>rank;
    
    public:
    DSU(int n)
    {
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x)
    {
        if(x==parent[x])
         return x;

        parent[x]=find(parent[x]);
        return parent[x];
    }

    void merge(int a,int b)
    {
        int pa=find(a);
        int pb=find(b);
        if(pa==pb) return;
        if(rank[pa]==rank[pb])
        {
            parent[pb]=pa;
            rank[pa]++;
        }
        else if(rank[pa]>rank[pb])
          parent[pb]=pa;
        else
         parent[pa]=pb;     
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        DSU dsu(n);
        unordered_map<long long,int> mp; //number and index
        for(int i=0;i<n;i++)
        {   
            if(mp.find(nums[i]) != mp.end())
             continue;
            if(mp.find(nums[i]-1) !=mp.end() && mp.find(nums[i]+1)!=mp.end())
            {
              dsu.merge(mp[nums[i]-1],mp[nums[i]+1]);
              dsu.merge(mp[nums[i]-1],i);
            }
            else if(mp.find(nums[i]-1) !=mp.end())
                 dsu.merge(mp[nums[i]-1],i);
            
            else if( mp.find(nums[i]+1)!=mp.end())
                 dsu.merge(mp[nums[i]+1],i);
            
            
            mp[nums[i]]=i;
            
        }
        int ans=0;
        unordered_map<int,int> mp2;
        for(int i=0;i<n;i++)
        {
            mp2[dsu.find(i)]++;
            ans=max(ans, mp2[dsu.find(i)]);
        }
        return ans;

    }
};