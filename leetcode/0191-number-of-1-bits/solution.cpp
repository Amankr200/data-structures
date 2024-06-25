class Solution {
public:
    int hammingWeight(int n) {
        int c = 0;
        while (n > 0) { 
// n = 5 (binary: 101)
// n & 1 evaluates to 1 (since 101 & 001 = 001).
// The condition if (n & 1) is true, so c is incremented to 1.
// n is right-shifted by 1 (n >>= 1), resulting in n = 2 (binary: 10).
// Second iteration:

// n = 2 (binary: 010)
// n & 1 evaluates to 0 (since 010 & 001 = 000).
// The condition if (n & 1) is false, so c remains 1.
// n is right-shifted by 1 (n >>= 1), resulting in n = 1 (binary: 1).
           
            if (n & 1) {
                c++;
            }
            n >>= 1; // Right shift n by 1 bit to process the next bit
        }
        return c;
    }
}; 
