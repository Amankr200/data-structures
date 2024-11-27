class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n =nums.size();
        int count =0;
            for (size_t i = 0; i < n ; ++i) {
         if (nums[i]!=0){
            nums.push_back(nums[i]);
            count++;
         }

    }
     nums.insert(nums.end(), (n-count), 0);
     nums.erase(nums.begin(), nums.begin() + n);
    }
};
