bool isValid(int capacity, int days, vector<int>& weights) {
    int curr = 0;
    int usedDays = 1;

    for(int w : weights) {
        if(curr + w <= capacity) {
            curr += w;
        } else {
            usedDays++;
            curr = w;
        }
    }

    return usedDays <= days;
}

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=INT_MIN;
        int h=0;
        for(int i=0;i<n;i++)
        {
            h+=weights[i];
            l=max(l,weights[i]);
        }

        int ans=INT_MAX;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(isValid(mid,days,weights))
            {
                ans=mid;
                h=mid-1;
            }
            else
             l=mid+1;
        }
        return ans;

    }
};