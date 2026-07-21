class Solution {
public:
    int divide(int dividend, int divisor) {
        
        // Special overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long before taking absolute value
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long quotient = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            // Double divisor while possible
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            quotient += multiple;
        }

        if (negative)
            quotient = -quotient;

        return (int)quotient;
    }
};
