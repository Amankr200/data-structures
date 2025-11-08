class Solution {
public:
    int query(vector<int>& bit, int i) {
        int ans = 0;
        while (i) {
            ans += bit[i], i -= i & -i;
        }
        return ans;
    }
    void update(vector<int>& bit, int i) {
        while (i < bit.size()) {
            bit[i]++, i += i & -i;
        }
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;
        vector<int> p(n + 1), bit(n * 2 + 1);
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] + (nums[i] == target ? 1 : -1);
        }
        for (int i = 0; i <= n; i++) {
            p[i] += n, ans += query(bit, p[i]), update(bit, p[i] + 1);
        }
        return ans;
    }
};
