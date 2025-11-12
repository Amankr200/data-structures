#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count1 = count(nums.begin(), nums.end(), 1);
        
        
        if (count1 > 0) return n - count1;
 
        int min_len = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    min_len = min(min_len, j - i + 1);
                    break;
                }
            }
        }

        if (min_len == INT_MAX) return -1;
        return (min_len - 1) + (n - 1);
    }
};

