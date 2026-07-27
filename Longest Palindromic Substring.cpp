#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            expand(s, i, i, start, maxLen);

            // Even length palindrome
            expand(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expand(string &s, int left, int right, int &start, int &maxLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }
};

int main() {
    Solution sol;
    string s = "babad";
    cout << sol.longestPalindrome(s) << endl; // "bab" or "aba"
    return 0;
}
