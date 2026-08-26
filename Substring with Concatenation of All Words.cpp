class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int wordLen = words[0].size();
        int totalWords = words.size();
        int totalLen = wordLen * totalWords;

        if (s.size() < totalLen) return ans;

        unordered_map<string, int> target;

        for (string word : words)
            target[word]++;

        // Try each possible starting offset
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int count = 0;

            unordered_map<string, int> window;

            for (int right = offset; right + wordLen <= s.size(); right += wordLen) {

                string word = s.substr(right, wordLen);

                // Word is not present in words
                if (!target.count(word)) {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                window[word]++;
                count++;

                // Too many occurrences of this word
                while (window[word] > target[word]) {
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // Found exactly all words
                if (count == totalWords) {
                    ans.push_back(left);

                    // Move forward to look for next answer
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};
