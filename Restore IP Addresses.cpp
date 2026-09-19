class Solution {
public:
    vector<string> result;

    void backtrack(string &s, int index, int parts, string current) {
        // If we have 4 parts
        if (parts == 4) {
            if (index == s.size()) {
                current.pop_back(); // remove last '.'
                result.push_back(current);
            }
            return;
        }

        // Try taking 1, 2, or 3 digits
        for (int len = 1; len <= 3; len++) {
            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

            // Leading zero is not allowed
            if (part.size() > 1 && part[0] == '0')
                continue;

            // Value must be <= 255
            if (stoi(part) > 255)
                continue;

            backtrack(s, index + len, parts + 1, current + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        result.clear();

        // An IP address needs 4 parts, each 1-3 digits
        if (s.size() < 4 || s.size() > 12)
            return result;

        backtrack(s, 0, 0, "");

        return result;
    }
};
