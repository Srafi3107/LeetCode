/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null or root matches p or q
        if (root == nullptr || root == p || root == q)
            return root;

        // Search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both sides return non-null, current node is the LCA
        if (left != nullptr && right != nullptr)
            return root;

        // If one side is null, return the other
        return (left != nullptr) ? left : right;
    }
};
