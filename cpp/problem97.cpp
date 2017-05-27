class Solution {
    // Memoization
    // Accepted. Runtime: 25 ms
#define vvvi vector<vector<vector<int>>>
#define vvi vector<vector<int>>
#define vi vector<int>
    
        int isInterleaveUtil(string s1, string s2, string s3,
                            int i, int j, int k, vvvi& dp) {
        if (i > s1.length() || j > s2.length() || k > s3.length())
            return 0;
        if (dp[i][j][k] == -1) {
            dp[i][j][k] = 0;
            if (i == s1.length() and j == s2.length() and
                k == s3.length())
                dp[i][j][k] = 1;
            if (k != s3.length()) {
                if (i != s1.length() and s1[i] == s3[k]
                    and isInterleaveUtil(s1, s2, s3, i+1, j, k+1, dp))
                    dp[i][j][k] = 1;
                if (j != s2.length() and s2[j] == s3[k]
                    and isInterleaveUtil(s1, s2, s3, i, j+1, k+1, dp))
                    dp[i][j][k] = 1;
            }     
        }
        return dp[i][j][k];
    }
    public:
    int isInterleave(string s1, string s2, string s3) {
        vvvi dp(s1.length() + 1, vvi(s2.length() + 1, vi(s3.length() + 1, -1)));
        isInterleaveUtil(s1, s2, s3, 0, 0, 0, dp);
        return dp[s1.length()][s2.length()][s3.length()];
    }
};
