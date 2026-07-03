class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& candidates, int target, int idx, vector<int>& path) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] > target)
                break;

            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> path;
        dfs(candidates, target, 0, path);

        return ans;
    }
};
