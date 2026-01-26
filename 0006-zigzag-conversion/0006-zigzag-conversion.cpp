class Solution {

public:
    string convert(string s, int numRows) {
        // Edge case
        if (numRows == 1 || numRows >= s.length())
            return s;

        int n = s.length();
        int T = 2 * numRows - 2;   // total cycle length
        string result = "";

        // Traverse row by row
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < n; j += T) {
                // Vertical character
                result += s[j];

                // Diagonal character (only for middle rows)
                int diag = j + T - 2 * i;
                if (i != 0 && i != numRows - 1 && diag < n) {
                    result += s[diag];
                }
            }
        }
        return result;
    }
};

       
