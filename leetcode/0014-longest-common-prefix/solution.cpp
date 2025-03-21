class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        sort(strs.begin(), strs.end());  // Sort the array

        string first = strs[0], last = strs[strs.size() - 1];  
        int i = 0;

        while (i < first.size() && first[i] == last[i]) {
            i++;
        }

        return first.substr(0, i);
    }
};

