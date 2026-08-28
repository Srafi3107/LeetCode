class Solution {
public:
    string countAndSay(int n) {
        string str = "1";

        for (int i = 1; i < n; i++) {
            string next = "";

            for (int j = 0; j < str.size(); ) {
                int count = 0;
                char ch = str[j];

                while (j < str.size() && str[j] == ch) {
                    count++;
                    j++;
                }

                next += to_string(count) + ch;
            }

            str = next;
        }

        return str;
    }
};
