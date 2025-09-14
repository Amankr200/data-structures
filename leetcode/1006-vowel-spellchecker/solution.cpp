class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;
        
        for (string w : wordlist) {
            string lower = toLower(w);
            string masked = maskVowels(lower);
            if (!caseMap.count(lower)) caseMap[lower] = w;
            if (!vowelMap.count(masked)) vowelMap[masked] = w;
        }
        
        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            string lower = toLower(q);
            if (caseMap.count(lower)) {
                ans.push_back(caseMap[lower]);
                continue;
            }
            string masked = maskVowels(lower);
            if (vowelMap.count(masked)) {
                ans.push_back(vowelMap[masked]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }

private:
    string toLower(string s) {
        for (char &c : s) c = tolower(c);
        return s;
    }
    
    string maskVowels(string s) {
        for (char &c : s) {
            if (isVowel(c)) c = '*';
        }
        return s;
    }
    
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
};

