/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

private:
    int dfs(TreeNode* node, int& maxSum) {
        if (!node) return 0;

      
        int leftGain = max(dfs(node->left, maxSum), 0);
        int rightGain = max(dfs(node->right, maxSum), 0);

        
        int currentMax = node->val + leftGain + rightGain;

        
        maxSum = max(maxSum, currentMax);

    
        return node->val + max(leftGain, rightGain);
    }
};
