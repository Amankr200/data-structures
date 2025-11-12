class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int ,int>freq;
        for (int i =0;i<n; i++){
            freq[nums[i]]++;
        }
        
        int sum=0;
       for(int i =0;i<n;i++){
           sum+=nums[i];
       }
       int sumz=0;
       for (auto &pi : freq) {
        sumz += pi.first;  
    }
     int z = sum-sumz;
       int totalsum= ((n*(n+1))/2);
       int numnotincluded = abs(totalsum-sumz);
       return {z,numnotincluded};
    }
};
