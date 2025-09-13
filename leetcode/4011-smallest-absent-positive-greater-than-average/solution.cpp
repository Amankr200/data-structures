class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        unordered_set<int> st;

        for (int x : nums) {
            sum += x;
            st.insert(x);
        }

        double avg = (double)sum / n;
        int candidate = max(1, (int)floor(avg) + 1);

        while (st.count(candidate)) {
            candidate++;
        }

        return candidate;
    }
};

