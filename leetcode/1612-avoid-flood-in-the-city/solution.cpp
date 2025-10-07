 class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, 1);
        unordered_map<int,int> last;
        set<int> dry;
        for(int i=0;i<n;i++){
            int r = rains[i];
            if(r==0){
                dry.insert(i);
                res[i]=1;
            } else {
                res[i]=-1;
                if(last.count(r)){
                    int prev = last[r];
                    auto it = dry.lower_bound(prev+1);
                    if(it==dry.end()) return {};
                    res[*it]=r;
                    dry.erase(it);
                }
                last[r]=i;
            }
        }
        return res;
    }
};

