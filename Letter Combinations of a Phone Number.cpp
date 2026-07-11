class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string curr;

        function<void(int)> backtrack = [&](int idx) {
            if (idx == digits.size()) {
                ans.push_back(curr);
                return;
            }

            string letters = mp[digits[idx] - '0'];
            for (char c : letters) {
                curr.push_back(c);
                backtrack(idx + 1);
                curr.pop_back();
            }
        };

        backtrack(0);
        return ans;
    }
};
