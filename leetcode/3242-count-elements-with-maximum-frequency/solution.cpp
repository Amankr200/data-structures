class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
      unordered_map<int, int> freq;
 
    for (int num : nums) {
        freq[num]++;
    }

    int maxFreq = 0;
  
    for (auto& p : freq) {
        if (p.second > maxFreq)
            maxFreq = p.second;
    }

    int count = 0;
 
    for (auto& p : freq) {
        if (p.second == maxFreq)
            count += p.second;
    }

    return count;
}

};
