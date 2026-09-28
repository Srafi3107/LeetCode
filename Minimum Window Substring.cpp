class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";

        vector<int> freq(128, 0);

        // Count required characters
        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        int right = 0;

        int required = t.length();
        int minLen = INT_MAX;
        int start = 0;

        while (right < s.length()) {

            // Include s[right]
            if (freq[s[right]] > 0) {
                required--;
            }

            freq[s[right]]--;
            right++;

            // Window contains all characters of t
            while (required == 0) {

                // Update minimum window
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                // Remove s[left]
                freq[s[left]]++;

                if (freq[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};