int calculate(string s) {
    int result = 0, number = 0, sign = 1;
    stack<int> stk;

    for (size_t i = 0; i < s.length(); ++i) {
        char ch = s[i];

        if (isdigit(ch)) {
            number = number * 10 + (ch - '0');
        } else if (ch == '+') {
            result += sign * number;
            number = 0;
            sign = 1;
        } else if (ch == '-') {
            result += sign * number;
            number = 0;
            sign = -1;
        } else if (ch == '(') {
           
            stk.push(result);
            stk.push(sign);
            result = 0;
            sign = 1;
        } else if (ch == ')') {
            result += sign * number;
            number = 0;
           
            result *= stk.top(); stk.pop(); 
            result += stk.top(); stk.pop(); 
        }
  
    }

    result += sign * number;
    return result;
}
