class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (node == nullptr)
                return;

            // Left
            inorder(node->left);

            // Root
            ans.push_back(node->val);

            // Right
            inorder(node->right);
        };

        inorder(root);

        return ans;
    }
};
