
void subs(int id,int n,vector<int>&nums,vector<int>&temp,vector<vector<int>>&res)
{
    if(id==n)
    { res.push_back(temp);
     return;
   }
    
    temp.push_back(nums[id]);
    subs(id+1,n,nums,temp,res);
    temp.pop_back();
    subs(id+1,n,nums,temp,res);
}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int id=0;
        int n=nums.size();
        vector<int>temp;
        subs(id,n,nums,temp,res);
        return res;
    }
};