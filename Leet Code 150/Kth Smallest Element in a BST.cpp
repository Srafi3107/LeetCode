class Solution {
public:
    int ans;
    int k;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        k--;
        if (k == 0) {
            ans = root->val;
            return;
        }

        inorder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        inorder(root);
        return ans;
    }
};
