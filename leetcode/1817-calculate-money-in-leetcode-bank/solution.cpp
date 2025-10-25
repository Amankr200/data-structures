class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int weekStart = 1;
        while (n > 0) {
            int days = min(n, 7);
            for (int i = 0; i < days; i++) {
                total += (weekStart + i);
            }
            weekStart++;
            n -= days;
        }
        return total;
    }
};
