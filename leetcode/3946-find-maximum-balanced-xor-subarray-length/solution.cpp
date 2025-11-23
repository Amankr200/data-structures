class Solution {
    private: 
    string getk(int xorofsum, int bal){
        return to_string(xorofsum) +"#"+to_string(bal);
    }
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        unordered_map<string,int>smap;
        int curxor=0;
        int curbal =0;
        int maxlen =0;
        smap[getk(0,0)]=-1;
        for(int i =0;i<n; ++i){
            curxor ^=nums[i];
            if(nums[i]%2==0){
                curbal++;
            }else{
                curbal--;
            }
            string curkey=getk(curxor,curbal);
            if(smap.count(curkey)){
                int pind=smap.at(curkey);
                maxlen = max(maxlen, i-pind);
                
            }else{
                smap[curkey]=i;
            }
        }
        return maxlen;
    }
};
