class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int k = nums.size();
        vector<int> ans(k);
        int j = 0;   

        for (int i = 0; i < n; i++) {
            ans[j++] = nums[i];      
            ans[j++] = nums[i + n]; 
        }

        return ans;
    }
};

