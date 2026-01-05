
void eval(int curr_sum,vector<int>&temp,int id,int target,vector<int>&candidates,vector<vector<int>>&res)
{
    if(curr_sum==target)
     {
        res.push_back(temp);
        return;
     }
    if(curr_sum>target || id>=candidates.size()) return;
    temp.push_back(candidates[id]);
    eval(curr_sum+candidates[id],temp,id+1,target,candidates,res); //included
    temp.pop_back();
    while(id<candidates.size()-1 && candidates[id]==candidates[id+1])
     id++;
    eval(curr_sum,temp,id+1,target,candidates,res); //not included
    return;
}


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort( candidates.begin(),candidates.end());
        vector<int>temp;
        int id=0;
        int curr_sum=0;
        eval(curr_sum,temp,id,target,candidates,res);
        return res;

    }
};