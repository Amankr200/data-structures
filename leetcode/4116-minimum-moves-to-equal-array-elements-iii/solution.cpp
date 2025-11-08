class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MIN;
        int total =0 ;
        
        for (int i =0 ; i<n; i++){
           if(nums[i]>max){
               max =nums[i];
           }
        }
        for (int i =0; i<n ;i++){
         total += ( max -nums[i]);
            
        }
        return total;
    }
};
