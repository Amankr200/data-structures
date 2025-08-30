class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string s = to_string(n);
        vector<int> freq(10, 0);

       
        for (char c : s) {
            freq[c - '0']++;
        }

        int ans = -1, minFreq = INT_MAX;

        
        for (int d = 0; d <= 9; d++) {
            if (freq[d] > 0) {  
                if (freq[d] < minFreq) {
                    minFreq = freq[d];
                    ans = d;
                } else if (freq[d] == minFreq && d < ans) {
                    ans = d;   
                }
            }
        }
        return ans;
    }
};

 
