class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> vect;

        for (size_t i = 0; i < nums.size(); i++) {

            if (i < nums.size() - 1 && nums[i + 1] == nums[i])
                continue;

            vect.push_back(nums[i]);
        }
        nums=vect;
        return nums.size();
    }
};

