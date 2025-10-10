class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        for (int start = n - k; start < n; ++start) {
            int sum = 0;
            for (int i = start; i >= 0; i -= k) {
                sum += energy[i];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};

