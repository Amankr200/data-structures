class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        vector<int> caltrivone = arrivals;
        int n = arrivals.size();
        unordered_map<int,int> freq;
        vector<char> kept(n, 0);
        int discards = 0;

        for (int i = 0; i < n; ++i) {
            int item = arrivals[i];
            if (i >= w) {
                int oldItem = arrivals[i - w];
                if (kept[i - w]) {
                    freq[oldItem]--;
                    if (freq[oldItem] == 0) freq.erase(oldItem);
                }
            }
            if (freq[item] >= m) {
                discards++;
                kept[i] = 0;
            } else {
                freq[item]++;
                kept[i] = 1;
            }
        }
        return discards;
    }
};

