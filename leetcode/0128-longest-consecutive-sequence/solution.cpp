class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {  // iterate over set (not nums → avoids duplicates)
            if (!s.count(num - 1)) {  // only start if num is sequence beginning
                int currentNum = num;
                int streak = 1;

                while (s.count(currentNum + 1)) {
                    currentNum++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }
        return longest;
    }
};

