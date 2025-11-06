class Solution {
public:
    // Helper to add two large numbers as strings
    string addStrings(string a, string b) {
        string res = "";
        int carry = 0, i = a.size() - 1, j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();

        // first number: num[0..i], second: num[i+1..j]
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string num1 = num.substr(0, i);
                string num2 = num.substr(i, j - i);

                // Skip numbers with leading zeros
                if ((num1.size() > 1 && num1[0] == '0') || 
                    (num2.size() > 1 && num2[0] == '0'))
                    continue;

                string sum;
                string next = addStrings(num1, num2);
                string temp = num1 + num2;

                // Keep generating sums until length >= num
                while (temp.size() < n) {
                    temp += next;
                    num1 = num2;
                    num2 = next;
                    next = addStrings(num1, num2);
                }

                if (temp == num) return true;
            }
        }
        return false;
    }
};

