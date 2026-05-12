class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        
        // Keep only lowercase letters and digits
        for (char c : s) {
            if (isalnum(c)) {
                temp += tolower(c);
            }
        }

        // Check palindrome
        int left = 0, right = temp.size() - 1;

        while (left < right) {
            if (temp[left] != temp[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
