class Solution {
public:
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> trees;

        // No nodes
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        // Try every value as the root
        for (int rootVal = start; rootVal <= end; rootVal++) {

            // Generate all possible left subtrees
            vector<TreeNode*> leftTrees =
                generate(start, rootVal - 1);

            // Generate all possible right subtrees
            vector<TreeNode*> rightTrees =
                generate(rootVal + 1, end);

            // Combine every left subtree with every right subtree
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {

                    TreeNode* root = new TreeNode(rootVal);

                    root->left = left;
                    root->right = right;

                    trees.push_back(root);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};
