 class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> visited;
        string ans = s;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            // Update the answer if we found a smaller string
            ans = min(ans, cur);

            // 1️⃣ Operation 1: Add 'a' to digits at odd indices
            string t1 = cur;
            for (int i = 1; i < t1.size(); i += 2) {
                t1[i] = (t1[i] - '0' + a) % 10 + '0';
            }

            if (!visited.count(t1)) {
                visited.insert(t1);
                q.push(t1);
            }

            // 2️⃣ Operation 2: Rotate right by 'b'
            string t2 = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
            if (!visited.count(t2)) {
                visited.insert(t2);
                q.push(t2);
            }
        }

        return ans;
    }
};
