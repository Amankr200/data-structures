class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

       
        auto isIncreasing = [&](int l, int r) {
            for (int i = l; i < r; i++) {
                if (nums[i] >= nums[i + 1])
                    return false;
            }
            return true;
        };
 
        for (int i = 0; i + 2 * k <= n; i++) {
            if (isIncreasing(i, i + k - 1) && isIncreasing(i + k, i + 2 * k - 1))
                return true;
        }

        return false;
    }
};

