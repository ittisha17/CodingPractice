class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        
        int n=citations.size();
        int ans=1;
        int sum=0;
        for(int i=n-1;i>=0;i--)
        {   
            sum+=citations[i];
            int h_id=min(n-i,citations[i]);
             ans=max(ans,h_id);
        }
        if(sum==0) return 0;
        return ans;
    }
};