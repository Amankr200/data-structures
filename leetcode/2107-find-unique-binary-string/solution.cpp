class Solution {
public:
    unordered_set<string> st;
    int n;
    string ans = "";

     
    bool generate(string curr, int i) {
        if (i == n) {
            if (st.find(curr) == st.end()) {  
                ans = curr;
                return true;
            }
            return false;
        }

      
        if (generate(curr + '0', i + 1)) return true;

         
        if (generate(curr + '1', i + 1)) return true;

        return false;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        st = unordered_set<string>(nums.begin(), nums.end());

        generate("", 0);
        return ans;
    }
};
