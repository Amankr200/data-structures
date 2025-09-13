
class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;

         
        for (char ch : s) {
            freq[ch]++;
        }

        string vowels = "aeiou";
        int maxVowel = 0, maxCons = 0;

        
        for (auto &p : freq) {
            char ch = p.first;
            int count = p.second;

            if (vowels.find(ch) != string::npos) {
                maxVowel = max(maxVowel, count);
            } else {
                maxCons = max(maxCons, count);
            }
        }

        return maxVowel + maxCons;
    }
};
