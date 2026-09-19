class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();

        // Lengths must match
        if (n + m != s3.size())
            return false;

        // dp[i][j] = whether first i chars of s1
        // and first j chars of s2 can form first i+j chars of s3
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {

                // Take character from s1
                if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }

                // Take character from s2
                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
    }
};
