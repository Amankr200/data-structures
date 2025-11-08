class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1), right(n,1);
        for(int i = 1; i < n; i++){
            if(nums[i] >= nums[i-1])left[i] = left[i-1]+1;
        }
        for(int i = n-2; i >= 0; i--){
            if(nums[i] <= nums[i+1])right[i] = right[i+1]+1;
        }
        int ans = *max_element(begin(left),end(left));
        for(int i = 0; i < n; i++){
            int len = 1;
            if(i > 0) len = max(len, left[i-1]+1);
            if(i < n-1) len = max(len,right[i+1]+1);
            if(i > 0 && i < n-1 && nums[i-1] <= nums[i+1]) len = max(len, left[i-1]+right[i+1]+1);
            ans = max(ans,len);
        }
        return ans;
    }
};
