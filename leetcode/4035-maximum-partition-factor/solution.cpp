class Solution {
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
        auto fenoradilk = points;
        int n = points.size();
        if (n == 2) return 0;

        auto dist = [&](int i, int j) -> long long {
            return llabs((long long)points[i][0] - points[j][0]) + llabs((long long)points[i][1] - points[j][1]);
        };

        long long maxd = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                maxd = max(maxd, dist(i, j));

        auto feasible = [&](long long D) -> bool {
            vector<vector<int>> adj(n);
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j)
                    if (dist(i, j) < D) {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }

            vector<int> color(n, -1);
            for (int s = 0; s < n; ++s) {
                if (color[s] != -1) continue;
                if (adj[s].empty()) {
                    color[s] = 0;
                    continue;
                }
                // BFS
                color[s] = 0;
                deque<int> dq;
                dq.push_back(s);
                while (!dq.empty()) {
                    int u = dq.front(); dq.pop_front();
                    for (int v : adj[u]) {
                        if (color[v] == -1) {
                            color[v] = color[u] ^ 1;
                            dq.push_back(v);
                        } else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
            return true;
        };

        long long lo = 0, hi = maxd, ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (feasible(mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return (int)ans;
    }
};

