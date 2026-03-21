class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        int c=0;
        for(int i=0;i<32;i++)
        {
            if( a&(1<<i) && b&(1<<i) )
              {
                if(c==0)
                   c=1;
                else               //three ones;
                   ans=ans | (1<<i);
              } 
            else if(a&(1<<i) || b&(1<<i))
            {
                if(c==0)
                 ans=ans| (1<<i);
                else 
                  c=1;
            }
            else
             {
                if(c!=0)
                 {ans=ans|(1<<i);
                  c=0;
                 }

             }
        }
        return ans;
    }
};