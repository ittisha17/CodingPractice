class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        int even_idx=n%2==0?n/2:n/2+1;
        int k=even_idx; //need to sum up value of top k largest elemnts
        priority_queue<int,vector<int>,greater<int>> pq;
        long long total_sqSum=0;
        for(int i=0;i<n;i++)
         total_sqSum+=1LL*nums[i]*nums[i];
        for(int i=0;i<k;i++)
        {
            pq.push(abs(nums[i]));
        }

        for(int i=k;i<n;i++)
        {
            if(abs(nums[i])>pq.top())
            {  pq.pop();
               pq.push(abs(nums[i]));
            }   
        }
        
        long long mx_square=0;
        while(!pq.empty())
        {
            long long num=pq.top();
            mx_square+=1LL*num*num;
            pq.pop();
        }

        long long ans=mx_square-(total_sqSum-mx_square);
        return ans;

    }
};