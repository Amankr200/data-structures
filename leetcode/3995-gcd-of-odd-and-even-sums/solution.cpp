#include <bits/stdc++.h>
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
            // Sum of first n odd numbers = n^2
    int sumOdd = n * n;

    // Sum of first n even numbers = n(n+1)
    int sumEven = n * (n + 1);
     return gcd(sumOdd,sumEven);
    }
   
};
