
int min_steps(int cnt_a,int copy_a,int n)
{
    if(cnt_a==n)
     return 0;
    if(cnt_a>n) return 1001;
    int ans=1001;
    if(copy_a>0)   //paste onoly when something is copied
     ans=min(ans,1+min_steps(cnt_a+copy_a,copy_a,n));
    if(copy_a!=cnt_a)
      ans=min(ans,1+min_steps(cnt_a,cnt_a,n)); //copy
    return ans;
    
}


class Solution {
public:
    int minSteps(int n) {
        int cnt_a=1;
        int copy_a=0;
        return min_steps(cnt_a,copy_a,n);
        
    }
};