class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);

        // Empty tree
        dp[0] = 1;

        // One node
        if (n >= 1)
            dp[1] = 1;

        for (int nodes = 2; nodes <= n; nodes++) {

            // Try every node as the root
            for (int root = 1; root <= nodes; root++) {

                int left = root - 1;
                int right = nodes - root;

                dp[nodes] += dp[left] * dp[right];
            }
        }

        return dp[n];
    }
};
