 class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrack(int index, string &s) {
        if (index == s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                // choose substring
                path.push_back(s.substr(index, i - index + 1));

                // explore further
                backtrack(i + 1, s);

                // undo choice (backtrack)
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(0, s);
        return res;
    }
};

