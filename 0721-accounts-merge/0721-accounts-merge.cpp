void combine_res(set<int>&comp,vector<vector<string>>&res,vector<vector<string>>& accounts)
{
   vector<string>temp;
   string name="";
   set<string> emails;
    for(auto id:comp)
    {   
        if(name=="")
          {name=accounts[id][0];
           temp.push_back(name);
          }
        for(int i=1;i<accounts[id].size();i++)
        {
            emails.insert(accounts[id][i]);
        }
           
    }
    for(auto e:emails)
    {
        temp.push_back(e);
    }
    sort(temp.begin()+1,temp.end());
    res.push_back(temp);
}

void dfs(int u,vector<bool>&visited,vector<vector<int>>&adj,set<int>&comp)
{
    visited[u]=true;
    comp.insert(u);
    for(int v:adj[u])
    {
        if(!visited[v]) 
         dfs(v,visited,adj,comp);
    }
     
}

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
                int n=accounts.size();

        vector<vector<int>> adj(n);
        unordered_map<string,int> mp;
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
              string mail=accounts[i][j];
              if(mp.find(mail)==mp.end())
               {
                 mp[mail]=i;
               }
              else //if mail already present
              { int u=i;
                int v=mp[mail];
                adj[u].push_back(v);
                adj[v].push_back(u);
              }
            }
        }

        vector<bool>visited(n,false);
        for(int i=0;i<n;i++)
        {   
            
            if(!visited[i])
            {   set<int> comp;
                dfs(i,visited,adj,comp);
                combine_res(comp,res,accounts);
            }
        }
        return res;


    }
};