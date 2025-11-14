class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> used;

    void backtrack(vector<int>& nums) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                temp.push_back(nums[i]);

                backtrack(nums);

                
                temp.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        backtrack(nums);
        return ans;
    }
};

