class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; ++a) {
            int b = n - a;
            
            if (!containsZero(a) && !containsZero(b)) {
                return {a, b};
            }
        }
        return {};   
    }
    
private:
    bool containsZero(int x) {
        while (x > 0) {
            if (x % 10 == 0)
                return true;
            x /= 10;
        }
        return false;
    }
};

