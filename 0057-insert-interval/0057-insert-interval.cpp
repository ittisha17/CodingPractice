
void merge(vector<vector<int>>&interval,vector<vector<int>>&res)
{
    res.push_back(interval[0]);
    int ps=0;
    for(int i=1;i<interval.size();i++)
    {
        if(interval[i][0]<=res[ps][1]) //overlap start of newsmaller the finish of prev
        {
            res[ps][0]=min(res[ps][0],interval[i][0]);
            res[ps][1]=max(res[ps][1],interval[i][1]);
        }
        else
         {
            res.push_back(interval[i]);
            ps++;
         }
    }

}
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        merge(intervals,res);
        return res;
        
    }
};