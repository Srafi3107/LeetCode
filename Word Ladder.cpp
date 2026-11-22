
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());

        // If endWord is not present
        if (st.find(endWord) == st.end()) {
            return 0;
        }

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        st.erase(beginWord);

        while (!q.empty()) {

            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // Target found
            if (word == endWord) {
                return steps;
            }

            // Change each character
            for (int i = 0; i < word.size(); i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    // Check if transformed word exists
                    if (st.find(word) != st.end()) {

                        q.push({word, steps + 1});

                        // Avoid visiting again
                        st.erase(word);
                    }
                }

                // Restore original character
                word[i] = original;
            }
        }

        return 0;
    }
};
