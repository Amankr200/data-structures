class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1; 

        int currSum = 0, result = 0;
        for (int x : nums) {
            currSum += (x % 2);  

            if (freq.find(currSum - k) != freq.end()) {
                result += freq[currSum - k];
            }

            freq[currSum]++;
        }
        return result;
    }
};
