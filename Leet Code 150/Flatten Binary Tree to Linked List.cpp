class Solution {
public:
    TreeNode* prev = nullptr; // keep track of previous node

    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->right); // flatten right subtree first
        flatten(root->left);  // then flatten left subtree

        root->right = prev;   // set right to previously visited node
        root->left = nullptr; // left must be null
        prev = root;          // update previous node
    }
};
