 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        long long occupied = LLONG_MIN;
        for (int x : nums) {
            long long low = (long long)x - k;
            long long high = (long long)x + k;
            if (occupied < high) {
                long long pick = max(occupied + 1, low);
                occupied = pick;
                ans++;
            }
        }
        return ans;
    }
};
