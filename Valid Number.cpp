class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool digitAfterE = true;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            // Digit
            if (isdigit(c)) {
                digitSeen = true;

                if (eSeen) {
                    digitAfterE = true;
                }
            }

            // Decimal point
            else if (c == '.') {
                // Dot cannot appear after e
                if (dotSeen || eSeen) {
                    return false;
                }

                dotSeen = true;
            }

            // Exponent e or E
            else if (c == 'e' || c == 'E') {
                // Must have a number before e
                // Only one exponent is allowed
                if (eSeen || !digitSeen) {
                    return false;
                }

                eSeen = true;
                digitAfterE = false;
            }

            // Sign + or -
            else if (c == '+' || c == '-') {
                // Sign is valid only at the beginning
                // or immediately after e/E
                if (i != 0 &&
                    s[i - 1] != 'e' &&
                    s[i - 1] != 'E') {
                    return false;
                }
            }

            // Invalid character
            else {
                return false;
            }
        }

        return digitSeen && digitAfterE;
    }
};
