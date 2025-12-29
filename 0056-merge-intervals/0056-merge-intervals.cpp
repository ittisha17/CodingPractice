class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end()); //sort according to start times
        vector<vector<int>> res;
        int pos=0;
        res.push_back(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=res[pos][1])  //start<prev ka end--->overlap
             {
                res[pos][0]=min(res[pos][0],intervals[i][0]);
                res[pos][1]=max(res[pos][1],intervals[i][1]);
             }
            else  //non overlap
            {
                res.push_back(intervals[i]);
                pos++;
            }
        }
        return res;

    }
};