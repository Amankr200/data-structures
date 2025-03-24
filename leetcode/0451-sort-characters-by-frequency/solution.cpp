class Solution {
public:
 string frequencySort(string s) {
    unordered_map<char, int> freq;

    // Step 1: Count frequency of each character
    for (char c : s) {
        freq[c]++;
    }

    // Step 2: Store characters in a vector
    vector<pair<char, int>> chars(freq.begin(), freq.end());

    // Step 3: Sort the vector based on frequency (descending order)
    sort(chars.begin(), chars.end(), [](pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second;
    });

    // Step 4: Build the result string
    string result = "";
    for (auto& it : chars) {
        result.append(it.second, it.first); // Append character it.second times
    }

    return result;
}
};
