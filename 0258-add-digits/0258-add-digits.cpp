int Calc(int num)
{  int sum=0;
    while(num)
    {
      sum+=num%10;
      num=num/10;
    }
    return sum;
}

class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num>=10)
        {
           sum=Calc(num);
           num=sum;
        }
        return num;
    }
};