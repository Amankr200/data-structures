class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>n;
        for(int i = 0 ; i < nums.size() ; i++){
           if (nums[i]== val) continue;
           n.push_back(nums[i]);
        }
        nums = n;
        return nums.size();
    }
};
