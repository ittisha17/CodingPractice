class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int curr_sum=0;
        int cnt_5=0;
        int cnt_10=0;
        for(int i=0;i<arr.size();i++)
        {   if(arr[i]==5)
             cnt_5++;
            else
            {
                if(arr[i]==10)
                {   cnt_10++;
                    if(cnt_5==0) return false;
                    else cnt_5--;
                }
                if(arr[i]==20)
                {
                    if((cnt_10>=1 && cnt_5>=1))
                    { cnt_10--;
                      cnt_5--;
                      continue;
                    }
                    else if(cnt_5>=3)
                    {
                        cnt_5-=3;
                        continue;
                    }
                     
                    else return false;
                }
            }
           
        }
        return true;
    }
};