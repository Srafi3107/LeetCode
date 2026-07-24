class Solution {
public:
    vector<string> result;

    void backtrack(string current, int open, int close, int n) {
        // A complete valid combination is formed
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if we still have opening brackets available
        if (open < n) {
            backtrack(current + "(", open + 1, close, n);
        }

        // Add ')' only when it will not make the sequence invalid
        if (close < open) {
            backtrack(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return result;
    }
};
