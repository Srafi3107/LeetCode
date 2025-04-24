class Solution {
public:
    bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> bracketPairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char ch : s) {
   
        if (bracketPairs.count(ch)) {
            
            if (!st.empty() && st.top() == bracketPairs[ch]) {
                st.pop();
            } else {
                return false;  
            }
        } else {
            st.push(ch);  
        }
    }

    return st.empty();  
}

};
