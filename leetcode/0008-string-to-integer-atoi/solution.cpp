
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long result = 0; // Use long to handle overflow before returning

        // Step 1: Ignore leading spaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Step 2: Check sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert numbers and check overflow
        while (i < s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Step 4: Handle overflow
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;

            i++;
        }

        return result * sign;
    }
};
