class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp; // key = number, value = index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // check if complement exists in map
            if (mp.find(complement) != mp.end()) {
                // found pair: return their indices
                return {mp[complement], i};
            }

            // otherwise, store current element with index
            mp[nums[i]] = i;
        }

        return {}; // no solution
    }
};

