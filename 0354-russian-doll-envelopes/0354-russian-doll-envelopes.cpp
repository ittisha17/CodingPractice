
struct mySort{
    bool operator()(vector<int>&v1,vector<int>&v2)
    {   
        if(v1[0]!=v2[0])
          return v1[0]<v2[0];
        return v1[1]>v2[1];
    }
};


class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),mySort());
        //now just have to find the longest increasing sequence accrding to height ending at i
        int n=envelopes.size();
        vector<int> lis;
        for(int i=0;i<n;i++)
        {   
            int height=envelopes[i][1];
            auto it=lower_bound(lis.begin(),lis.end(),height);
            if(it==lis.end())
             lis.push_back(height);
            else
             *it=height;
        }
        return lis.size();

    }
};