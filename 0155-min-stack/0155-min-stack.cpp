class MinStack {
    stack<int>st;
    stack<int>min_st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min_st.empty())
         min_st.push(val);
        else
        {
            if(val<=min_st.top())
             min_st.push(val);
        }
    }
    
    void pop() {
        int elem=st.top();
        if(elem==min_st.top())
         min_st.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */