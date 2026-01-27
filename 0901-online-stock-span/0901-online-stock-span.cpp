class StockSpanner {
public:
    vector<int> vec;
    stack<int>st;
    StockSpanner() {
        vec={};
    }
    
    int next(int price) {
        // stack<int>st;
        int ans;
        if(vec.empty()) 
            ans=1;
        else{
        // for(int i=0;i<vec.size();i++)
        //  st.push(i); 

        while(!st.empty() && price>=vec[st.top()])
           st.pop();
        if(st.empty())
          ans=vec.size()+1;
        else ans=vec.size()-st.top();
        }
        vec.push_back(price);
        st.push(vec.size()-1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */