class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int large=9;
        string curr="";
        int dig=0;
        while(sum!=0)
        {
            while(sum>=large)
            {
                curr+=to_string(large);
                sum-=large;
                dig++;
            }
            while(large>sum)
             large--;
        }
        if(dig>num) return "";
        while(dig<num)
         {curr+="0";
         dig++;}

        return curr;

    }
};