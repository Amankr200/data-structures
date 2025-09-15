class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int count = 0;
        bool valid = true;

        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                if (valid) count++;
                valid = true;
            } else {
                if (broken.count(text[i])) {
                    valid = false;
                }
            }
        }
        return count;
    }
};
