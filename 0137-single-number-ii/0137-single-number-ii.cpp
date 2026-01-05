class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int num=0;
       for(int i=0;i<32;i++)
       { int cnt_set=0;
         for(int j=0;j<nums.size();j++)
         {  
            if(nums[j]>>i&1) //set bit
             cnt_set++;
         }
         if(cnt_set%3==1)
          num+=1<<i;
       }
       return num;
    }
};