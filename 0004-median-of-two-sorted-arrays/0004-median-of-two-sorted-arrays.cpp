class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();

        if(m>n)
         swap(nums1,nums2);

        m=nums1.size();
        n=nums2.size(); 
        int l=0;
        int h=m;
        while(l<=h)
        {
            int mid1=l+(h-l)/2;

            int mid2=(m+n+1)/2-mid1;
            int mn1=mid1==0?INT_MIN:nums1[mid1-1];
            int mn2=mid2==0?INT_MIN:nums2[mid2-1];

            int mx1=mid1==m?INT_MAX:nums1[mid1];
            int mx2=mid2==n?INT_MAX:nums2[mid2];

            if(mn1>mx2)
             h=mid1-1;
            else if(mn2>mx1)
             l=mid1+1;
            else if(mn1<=mx2 && mn2<=mx1)
            { if((m+n)%2==1) //odd number of elements
               return max(mn1,mn2);
              else  //even elemts
               return float((max(mn1,mn2)+min(mx1,mx2)))/2;                
            }
        }
        return 0;
    }
};