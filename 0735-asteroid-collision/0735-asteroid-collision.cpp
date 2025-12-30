bool isOpp(int a,int b)
{
    return((a<0 && b>0) || (a>0 && b<0));
}

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n=asteroids.size();
        vector<int>res;
        for(int i=0;i<n;i++)
        {  
           int elem=asteroids[i];
           bool incl=true;
           while(!st.empty()  && st.top()>0 && elem<0)
           {
              if(abs(elem)>abs(st.top()))
                st.pop();
               else if(abs(elem)==abs(st.top()))
                {
                    st.pop();
                    incl=false;
                    break;
                }
              else
               {
                incl=false;
                break;
               }
                 
           }
           if(incl)
             st.push(elem);
        }
        while(!st.empty())
        { res.push_back(st.top());
         st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};