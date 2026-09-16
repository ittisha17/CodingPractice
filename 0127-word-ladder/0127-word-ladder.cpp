class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,0});
        set<string> st(wordList.begin(),wordList.end());
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            string w=p.first;
            int d=p.second;
            if(w==endWord)
             return d+1;
            for(int i=0;i<w.size();i++)
            {
                for(char ch='a';ch<='z';ch++)
                {
                    string new_w=w;
                    new_w[i]=ch;
                    if(new_w!=w && st.find(new_w)!=st.end())
                     {
                        q.push({new_w,d+1});
                        st.erase(new_w);
                     }
                }
            }
        }
        return 0;

    }
};