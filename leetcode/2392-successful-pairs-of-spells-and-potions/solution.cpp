class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> res;
        res.reserve(spells.size());
        for (int x : spells) {
            long long s = x;
            long long need = (success + s - 1) / s;
            auto it = lower_bound(potions.begin(), potions.end(), need);
            res.push_back(n - int(it - potions.begin()));
        }
        return res;
    }
};
