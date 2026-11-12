
class Solution {
public:
    int height(TreeNode* root) {

        // Empty tree has height 0
        if (root == NULL) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Check if either subtree is unbalanced
        if (leftHeight == -1 || rightHeight == -1) {
            return -1;
        }

        // Check height difference
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Return the height of current node
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
