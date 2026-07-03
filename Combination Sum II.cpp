class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& candidates, int target, int idx, vector<int>& path) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            path.push_back(candidates[i]);

            // Use each element only once
            dfs(candidates, target - candidates[i], i + 1, path);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> path;
        dfs(candidates, target, 0, path);

        return ans;
    }
};
