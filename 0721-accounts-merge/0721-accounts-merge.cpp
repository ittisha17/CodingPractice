class DSU{
    public:
    int n;
    vector<int> parent;
    vector<int> rank;

    DSU(int n)
    {
        this->n=n;
        for(int i=0;i<n;i++)
        { parent.push_back(i);
          rank.push_back(0);
        }
    }
     
    int find(int x)
    {
        if(parent[x]==x)
         return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int u,int v)
    {   
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)
         return;
        
        if(rank[pu]==rank[pv])
        {
            parent[pv]=pu;
            rank[pu]++;
        }
        else if(rank[pu]>rank[pv])
         parent[pv]=pu;
        else
         parent[pu]=pv;
    }
};



class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU dsu(n);

        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {;
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j])==mp.end())
                 mp[accounts[i][j]]=i;
                else
                 dsu.unite(i,mp[accounts[i][j]]);   
            }
        }
        
        unordered_map<int,vector<string>> groups;
        for(auto p:mp){
            string mail=p.first;
            int acnt=p.second;
            int parent=dsu.find(acnt);
            groups[parent].push_back(mail);
        }
       
       vector<vector<string>> res;
       for(auto it:groups)
       {
         int parent=it.first;
         vector<string> mails=it.second;
         sort(mails.begin(),mails.end());
         vector<string> temp;
         temp.push_back(accounts[parent][0]);
         for(auto s:mails)
          temp.push_back(s);
         res.push_back(temp);

       }
       return res;

    }
};