
int calc(int a,int b,string op)
{
    if(op=="+")
     return a+b;
    else if(op=="-")
     return a-b;
    else if(op=="/")
     return a/b;
    else
     return a*b;
    
}


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans;
        stack<int> num;
        int n=tokens.size();
        for(int i=0;i<n;i++)
        {   
            string ch=tokens[i];
            // if(ch[0]>='0' && ch[0]<='9')  //is a digit
          
            if(ch=="+" || ch=="-" || ch=="*" || ch=="/")//operator
            {
                int op2=num.top();
                num.pop();
                int op1=num.top();
                num.pop();
                ans=calc(op1,op2,ch);
                num.push(ans); }
            else
                num.push(stoi(ch));

        }
        return num.top();

    }
};