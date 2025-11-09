class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>indices;
        int n=nums.size();
        for(int i=0;i<n;i++){
            indices[nums[i]].push_back(i);
        }
        int mindistance =INT_MAX;

        for(auto & pair : indices){
            vector<int>&pos = pair.second;
            if(pos.size()<3) continue;
            for(int i =0 ; i<pos.size()-2;i++){
                int dist = abs (pos[i]-pos[i+1])+abs(pos[i+1]-pos[i+2])+abs(pos[i+2]-pos[i]);
                mindistance=min(mindistance,dist);
            }
        }
         
       return mindistance==INT_MAX ?-1:mindistance;
    }
};
