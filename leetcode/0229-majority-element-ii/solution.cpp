class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int k = nums.size();
        int j= k/3;
         map<int, int> freq;
        vector<int> result;
   
    for (int i = 0; i < k; i++) {
        freq[nums[i]]++;
            if (freq[nums[i]] == j + 1) {
            result.push_back(nums[i]);
        }
    }
    
    return result;
    }
};
