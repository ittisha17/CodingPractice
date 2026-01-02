
void eval(vector<int>&temp,vector<vector<int>>&res,vector<int>&nums,set<int>&st)
{
    if(temp.size()==nums.size())
    {   res.push_back(temp);
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(st.find(nums[i])==st.end())
        {
          temp.push_back(nums[i]);
          st.insert(nums[i]);
          eval(temp,res,nums,st);
          st.erase(nums[i]);
          temp.pop_back();
        }
    }
    return;
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>temp;
        set<int>st;
        eval(temp,res,nums,st);
        return res;
    }
};