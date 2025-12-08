class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        int n_sq = n * n;
        
        for (int a = 1; a <= n; ++a) {
            int a_sq = a * a;
            
            for (int b = 1; b <= n; ++b) {
                int b_sq = b * b;
                
                int c_sq = a_sq + b_sq;
                
                if (c_sq > n_sq) {
                    break;
                }
                
                int c = static_cast<int>(sqrt(c_sq));
                
                if (c * c == c_sq) {
                    count++;
                }
            }
        }
        return count;
    }
};
