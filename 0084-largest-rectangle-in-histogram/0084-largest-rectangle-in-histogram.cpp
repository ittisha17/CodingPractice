class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> lmin(n);
        vector<int> rmin(n);
        
        stack<int>st;
        for(int i=0;i<n;i++)
        { 
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
             lmin[i]=-1;
            else
             lmin[i]=st.top();
            st.push(i);
        }

        st=stack<int>();

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
             rmin[i]=n;
            else
             rmin[i]=st.top();
            st.push(i);
        }

        int mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,(rmin[i]-lmin[i]-1)*heights[i]);
        }
        return mx;
    }
};