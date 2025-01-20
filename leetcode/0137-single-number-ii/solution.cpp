class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));

        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1 || nums[i] != nums[i + 1]) {
                return nums[i];
            }
            i++;
            i++;
        }

        return -1;
    }
};
