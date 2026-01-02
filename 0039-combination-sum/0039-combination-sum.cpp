void Solve(int id,int curr_sum,int target,  vector<vector<int>>&res,vector<int>&temp,vector<int>&vec)
{
    if(curr_sum==target)
    {
        res.push_back(temp);
        return;
    }

    if(id==vec.size() || curr_sum>target) return;
    temp.push_back(vec[id]);
    Solve(id,curr_sum+vec[id],target,res,temp,vec);
    temp.pop_back();
    Solve(id+1,curr_sum,target,res,temp,vec);
}



class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int curr_sum=0;
        int id=0;
        vector<int>temp;
        Solve(id,curr_sum,target,res,temp,candidates);
        return res;
    }
};