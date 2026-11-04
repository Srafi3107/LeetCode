class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        // Visit left subtree
        inorder(root->left);

        // Find incorrect order
        if (prev != nullptr && prev->val > root->val) {

            if (first == nullptr) {
                first = prev;
            }

            second = root;
        }

        prev = root;

        // Visit right subtree
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {

        inorder(root);

        // Swap the two incorrect values
        swap(first->val, second->val);
    }
};
