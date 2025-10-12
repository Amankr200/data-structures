class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();
        vector<int> prefix(n);
        prefix[0] = s[0] - 'a' + 1;
        for (int i = 1; i < n; i++) 
            prefix[i] = prefix[i - 1] + (s[i] - 'a' + 1);
        int total = prefix[n - 1];
        for (int i = 0; i < n - 1; i++) 
            if (prefix[i] == total - prefix[i]) return true;
        return false;
    }
};

