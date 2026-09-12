class Solution {
public:
    int calculate(string s) {
        stack<int> st; // Stores [running_result, sign_before_bracket]
        long long total = 0;
        int sign = 1;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            
            if (isdigit(ch)) {
                long long val = 0;
                while (i < n && isdigit(s[i])) {
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                i--; // Step back to offset outer loop increment
                total += sign * val;
            } 
            else if (ch == '+') {
                sign = 1;
            } 
            else if (ch == '-') {
                sign = -1;
            } 
            else if (ch == '(') {
                // Save current state before entering sub-expression
                st.push(total);
                st.push(sign);
                total = 0;
                sign = 1;
            } 
            else if (ch == ')') {
                // Resolve expression inside brackets and combine with outer context
                int prevSign = st.top(); st.pop();
                int prevTotal = st.top(); st.pop();
                total = prevTotal + prevSign * total;
            }
        }
        
        return total;
    }
};