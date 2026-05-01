class Solution {
public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {

        map<int, vector<int>> mp1, mp2;

        // Build adjacency lists
        for(int i = 0; i < 2*e; i += 2)
        {
            mp1[A[i]].push_back(A[i+1]);
            mp2[B[i]].push_back(B[i+1]);
        }

        // Check for every node
        for(int i = 1; i <= n; i++)
        {
            vector<int> &v1 = mp1[i];
            vector<int> &v2 = mp2[i];

            if(v1.size() != v2.size())
                return 0;

            int l = 0, r = v2.size() - 1;

            while(l < v1.size())
            {
                if(v1[l] != v2[r])
                    return 0;
                l++;
                r--;
            }
        }

        return 1;
    }
};