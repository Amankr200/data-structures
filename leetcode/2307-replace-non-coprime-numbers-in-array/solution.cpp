class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        
        for (int num : nums) {
            while (!st.empty()) {
                int gcd = std::gcd(st.back(), num);
                if (gcd == 1) break;
                
               
                num = (st.back() / gcd) * num;
                st.pop_back();
            }
            st.push_back(num);
        }
        
        return st;
    }
};

