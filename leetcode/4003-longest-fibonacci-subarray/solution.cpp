class Solution {
public:
    int  longestSubarray(vector<int>& nums) {
        auto valtoremin = nums;
        int n = nums.size(), ans = 2, len = 2;
        for (int i = 2; i < n; i++) {
            if (nums[i] == nums[i - 1] + nums[i - 2]) len++;
            else len = 2;
            ans = max(ans, len);
        }
        return ans;
    }
};

