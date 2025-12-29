class Solution {
public:
    int trailingZeroes(int n) {
        int cnt=0;
        int num=5;
        while(num<=n)
        {
            cnt+=n/num;
            num*=5;
        }
        return cnt;
    }
};