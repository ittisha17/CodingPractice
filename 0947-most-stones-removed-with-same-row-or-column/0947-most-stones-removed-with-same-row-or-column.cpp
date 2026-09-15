
class DSU{
    public:
    int n;
    vector<int> parent;
    vector<int>rank;

    DSU(int n)
    {
        this->n=n;
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x)
    {
        if(parent[x]==x)
         return x;
        return parent[x]=find(parent[x]);
    }

    bool isunite(int u,int v)
    {
        int pu=find(u);
        int pv=find(v);

        if(pv==pu) return false;
        if(rank[pv]==rank[pu])
        {
            parent[pv]=pu;
            rank[pu]++;
        }
        else if(rank[pu]>rank[pv])
          parent[pv]=pu;
        else
         parent[pu]=pv;
        return true;
    }

};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DSU dsu(n);
        unordered_map<int,int> mp_row;
        unordered_map<int,int> mp_col;
        int cnt=0;
        for(int i=0;i<n;i++)
        { 
            int r=stones[i][0];
            int c=stones[i][1];

            if(mp_row.find(r)!=mp_row.end())
            {
                if(dsu.isunite(mp_row[r],i))
               { 
                cnt++;
               }
            }

            if(mp_col.find(c)!=mp_col.end())
            {  if(dsu.isunite(mp_col[c],i))
              { 
               cnt++;
              }
            }
            mp_row[r]=i;
            mp_col[c]=i;
             
        }
        return cnt;
    }
};