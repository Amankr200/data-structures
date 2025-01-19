class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int result = INT_MIN;
        int total_ones = count(begin(s), end(s), '1');
        
        int zeros = 0;
        
        for(int i = 0; i < n-1; i++) {
            if(s[i] == '1') {
                total_ones--;
            } else {
                zeros++;
            }
            
            result = max(result, zeros + total_ones);
        }
        
        return result;
    }
};


