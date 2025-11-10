class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        vector<int> st;
        for (int x : nums) {
            if (x == 0) {
                st.clear();
            } else {
                while (!st.empty() && st.back() > x) st.pop_back();
                if (st.empty() || st.back() < x) {
                    st.push_back(x);
                    ans++;
                }
                // if st.back() == x: nothing to do
            }
        }
        return ans;
    }
};

