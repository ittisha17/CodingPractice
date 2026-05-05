class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        vector<int>res;
        set<int>st;
        int i=0;
        int j=0;
        int n=a.size();
        int m=b.size();
        while(i<n && j<m)
        {
            if(a[i]<b[j] && st.find(a[i])==st.end())
            {
                res.push_back(a[i]);
                 st.insert(a[i]);
                while(i<n-1 && a[i+1]==a[i])
                  i++;
              
                i++;
            }
            else if(b[j]<a[i] && st.find(b[j])==st.end())
            {
                res.push_back(b[j]);
                st.insert(b[j]);
                while(j<m-1 && b[j+1]==b[j])
                  j++;
                
                j++;
            }
            else //both same
            {
                if(st.find(b[j])==st.end())
                 res.push_back(b[j]);
                 st.insert(b[j]);
                while(j<m-1 && b[j+1]==b[j])
                  j++;
                 while(i<n-1 && a[i+1]==a[i])
                  i++;
                
                i++;
                j++;
            }
            
        }
        while(i<n)
        {
            if(st.find(a[i])==st.end())
             res.push_back(a[i]);
            st.insert(a[i]);
            while(i<n-1 && a[i+1]==a[i])
             i++;
            i++;
        }
        
         while(j<m)
        {
            if(st.find(b[j])==st.end())
             res.push_back(b[j]);
             st.insert(b[j]);
             while(j<m-1 && b[j+1]==b[j])
             j++;
            j++;
        }
        return res;
    }
};