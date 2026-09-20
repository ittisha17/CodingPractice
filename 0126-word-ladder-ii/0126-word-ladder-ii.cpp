


void store_path(string curr_w,string &beginWord,unordered_map<string,vector<string>> &node_par,vector<vector<string>>&res,vector<string> &temp)
{ 
    if(curr_w==beginWord)
     {
        temp.push_back(curr_w);
        vector<string> path=temp;
        reverse(path.begin(),path.end());
        res.push_back(path);
        temp.pop_back();
        return;
     }

     for(string par:node_par[curr_w])
     {
         temp.push_back(curr_w);
         store_path(par,beginWord,node_par,res,temp);
         temp.pop_back();
     }
  //if curr becomes begin
    // push begin in temp
    // puh temp in res;  
//   for every curr word we basically either take the parent at id in its vector or we dont take it and we move to nect node?


}

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        set<string> words(wordList.begin(),wordList.end());
        if(words.find(endWord)==words.end()) return{};

        queue<pair<string,int>> q;
        unordered_map<string,vector<string>> node_par;

        node_par[beginWord]={""};
        unordered_map<string,int> dist;
        q.push({beginWord,0});
     
        while(!q.empty())
        {
            auto pu=q.front();
            q.pop();
            string u=pu.first;
            int d=pu.second;
            if(u==endWord )
             { 
                 continue;    
             }
            for(int i=0;i<u.size();i++)
            {
                for(char ch='a';ch<='z';ch++)
                {
                    string new_w=u;
                    new_w[i]=ch;
                    if(words.find(new_w)!=words.end())
                    {   
                        if(dist.find(new_w) == dist.end())
                        {
                        dist[new_w] = d + 1;
                        node_par[new_w].push_back(u);
                        q.push({new_w, d + 1});
                        }
                        else if(dist[new_w]==d+1)
                          node_par[new_w].push_back(u);
                         
                    }
                }
            }

        }
        vector<string>temp;
        store_path(endWord,beginWord,node_par,res,temp);
        return res;



    }
};