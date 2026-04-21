
void solve(int idx,int n,vector<int>&cookies,vector<int>&child,int &mn,int k)
{
    if(idx==n)
    {
        //max of all the values in child
        int mx=INT_MIN;
        for(int i=1;i<=k;i++)
         mx=max(mx,child[i]);
        //min of all
        mn=min(mn,mx);
        return;
    }
    for(int i=1;i<=k;i++) //for every child
    {
        child[i]+=cookies[idx];
        solve(idx+1,n,cookies,child,mn,k);
        child[i]-=cookies[idx];
    }
}


class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k+1,0); //stores the cookies got by each child
        int idx=0;
        int n=cookies.size();
        int mn=INT_MAX;
        solve(idx,n,cookies,child,mn,k);
        return mn;
    }
};