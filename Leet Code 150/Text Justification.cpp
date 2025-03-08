class Solution {
public:
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    vector<string> cur;
    int num_of_letters = 0;
    
    for (const string& word : words) {
        if (num_of_letters + word.length() + cur.size() > maxWidth) {
            int spaces = maxWidth - num_of_letters;
            for (int i = 0; i < spaces; ++i) {
                cur[i % (cur.size() - 1 ? cur.size() - 1 : 1)] += " ";
            }
            string line;
            for (const string& w : cur) line += w;
            res.push_back(line);
            cur.clear();
            num_of_letters = 0;
        }
        cur.push_back(word);
        num_of_letters += word.length();
    }
    
    string last_line;
    for (size_t i = 0; i < cur.size(); ++i) {
        if (i > 0) last_line += " ";
        last_line += cur[i];
    }
    last_line.append(maxWidth - last_line.length(), ' ');
    res.push_back(last_line);
    
    return res;
}
};
