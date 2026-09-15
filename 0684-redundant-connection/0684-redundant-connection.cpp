class DSU{
    public:
     int n;
     vector<int> parent;
     vector<int> rank;
     
    DSU(int n)
    {
        this->n=n;
        for(int i=0;i<n;i++)
         {parent.push_back(i);
          rank.push_back(0);
         }
    }

     int find(int x)
     {
        if(parent[x]==x)
         return x;
        return parent[x]=find(parent[x]);
     }

     bool isunion(int a,int b)
     {
        int parA=find(a);
        int parB=find(b);
        if(parA==parB) //already joined
         return false;
        if(rank[parA]==rank[parB])
        {
            parent[parB]=parA;
            rank[parA]++;
        }
         else if(rank[parA]>rank[parB])
           {
             parent[parB]=parA;
           }
        else
         parent[parA]=parB;
        return true;
     }

    
};



class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n+1);
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            if(dsu.isunion(u,v)==false)
             return {u,v};
        }
        return {};
    }
};