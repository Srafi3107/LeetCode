class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int start, vector<int>& current) {
        // Every current selection is a valid subset
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            // Choose
            current.push_back(nums[i]);

            // Explore
            backtrack(nums, i + 1, current);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        backtrack(nums, 0, current);
        return result;
    }
};
