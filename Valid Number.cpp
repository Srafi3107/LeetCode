class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool digitAfterE = true;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];


            if (isdigit(c)) {
                digitSeen = true;

                if (eSeen) {
                    digitAfterE = true;
                }
            }

            else if (c == '.') {

                if (dotSeen || eSeen) {
                    return false;
                }

                dotSeen = true;
            }

            else if (c == 'e' || c == 'E') {

                if (eSeen || !digitSeen) {
                    return false;
                }

                eSeen = true;
                digitAfterE = false;
            }

            else if (c == '+' || c == '-') {
                if (i != 0 &&
                    s[i - 1] != 'e' &&
                    s[i - 1] != 'E') {
                    return false;
                }
            }

            else {
                return false;
            }
        }

        return digitSeen && digitAfterE;
    }
};
