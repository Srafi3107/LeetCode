class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word = "";

        // Split string by spaces
        for (char c : s) {
            if (c == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        words.push_back(word);

        // Size must match
        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string w = words[i];

            // Check char -> word mapping
            if (mp1.count(ch)) {
                if (mp1[ch] != w) {
                    return false;
                }
            } else {
                mp1[ch] = w;
            }

            // Check word -> char mapping
            if (mp2.count(w)) {
                if (mp2[w] != ch) {
                    return false;
                }
            } else {
                mp2[w] = ch;
            }
        }

        return true;
    }
};
