class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(string s1, string s2) {
        if (s1 == s2)
            return true;

        string key = s1 + "#" + s2;

        if (memo.count(key))
            return memo[key];

        // If character frequencies are different, impossible
        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a != b)
            return memo[key] = false;

        int n = s1.size();

        // Try every possible split
        for (int i = 1; i < n; i++) {

            // Case 1: No swap
            if (solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // Case 2: Swap
            if (solve(s1.substr(0, i), s2.substr(n - i)) &&
                solve(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;

        return solve(s1, s2);
    }
};
