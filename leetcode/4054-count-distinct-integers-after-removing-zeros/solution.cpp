class Solution {
public:
    long long countDistinct(long long n) {
        string s = to_string(n);
        int len = s.size();
        
         
        long long ans = 0;
        for (int digits = 1; digits < len; digits++) {
            ans += pow(9, digits);
        }

        
        for (int i = 0; i < len; i++) {
            int d = s[i] - '0';

          
            if (d == 0) return ans;  

            ans += (d - 1) * pow(9, len - i - 1);
 
            if (d == 0) break;
        }

        
        if (s.find('0') == string::npos) ans++;

        return ans;
    }
};

