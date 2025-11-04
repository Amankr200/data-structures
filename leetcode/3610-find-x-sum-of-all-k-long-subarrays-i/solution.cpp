 
class Solution {
public:
    
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i + k <= n; ++i) {
          
            unordered_map<int,int> freq;
            for (int j = i; j < i + k; ++j) freq[nums[j]]++;

        
            vector<pair<int,int>> v;
            v.reserve(freq.size());
            for (auto &p : freq) v.emplace_back(p.first, p.second);
 
            sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b){
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });
 
            unordered_set<int> keep;
            for (int t = 0; t < (int)v.size() && t < x; ++t) keep.insert(v[t].first);

           
            int sum = 0;
            for (int j = i; j < i + k; ++j)
                if (keep.count(nums[j])) sum += nums[j];

            ans.push_back(sum);
        }
        return ans;
    }
};
