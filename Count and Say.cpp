class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 1; i < n; i++) {
            string next = "";

            for (int j = 0; j < s.size(); ) {
                int count = 0;
                char ch = s[j];

                while (j < s.size() && s[j] == ch) {
                    count++;
                    j++;
                }

                next += to_string(count) + ch;
            }

            s = next;
        }

        return s;
    }
};
