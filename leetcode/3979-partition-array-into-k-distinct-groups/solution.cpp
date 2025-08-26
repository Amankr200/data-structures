class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if (k == 1) return true;
        if (nums.size() % k != 0) return false;

        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int maxFreq = 0;
        for (auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }

         
        if (nums.size() == k) {
            return (maxFreq == 1);
        }

        
        if (maxFreq > nums.size() / k) {
            return false;
        }
        return true;
    }
};

