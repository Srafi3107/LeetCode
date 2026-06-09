Class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int start, int n, int k, vector<int>& curr) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            backtrack(i + 1, n, k, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        backtrack(1, n, k, curr);
        return ans;
    }
};
