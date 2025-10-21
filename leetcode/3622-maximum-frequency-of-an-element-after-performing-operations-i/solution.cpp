 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        unordered_map<long long,int> freq;
        for (int x : nums) ++freq[x];
        map<long long,int> events;
        for (int x : nums) {
            long long L = (long long)x - k;
            long long R1 = (long long)x + k + 1;
            events[L] += 1;
            events[R1] -= 1;
        }
        set<long long> coords;
        for (auto &p : events) coords.insert(p.first);
        for (auto &p : freq) coords.insert(p.first);
        vector<long long> vcoords(coords.begin(), coords.end());
        long long cur = 0;
        int ans = 1;
        for (size_t i = 0; i < vcoords.size(); ++i) {
            long long x = vcoords[i];
            if (events.count(x)) cur += events[x];
            int eq = freq.count(x) ? freq[x] : 0;
            ans = max(ans, (int)min<long long>(cur, eq + (long long)numOperations));
            if (i + 1 < vcoords.size()) {
                long long nextx = vcoords[i+1];
                if (nextx - x > 1) {
                    ans = max(ans, (int)min<long long>(cur, (long long)numOperations));
                }
            }
        }
        return min(ans, n);
    }
};
