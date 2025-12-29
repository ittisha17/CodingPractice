class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n=nums.size();
        int st=0;
        int i=0;
        while(i<n)
        {
            while(i<n-1 && nums[i]==nums[i+1]-1)
             i++;
            string curr="";
            if(i==st)
            { curr+=to_string(nums[i]);
              st++;
              res.push_back(curr);
            }
            else
            {
                curr+=to_string(nums[st]);
                curr+="->";
                curr+=to_string(nums[i]);
                st=i+1;
                res.push_back(curr);
            }
            i++;
        }
        if(st<n)
        { 
            if(i-st>1)
              res.push_back(to_string(nums[st])+"->"+to_string(nums[i-1]));
            else 
             res.push_back(to_string(nums[st]));
        }
       
         return res;


    }
};