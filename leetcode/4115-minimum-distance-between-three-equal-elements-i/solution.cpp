class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>indices;
        int n =nums.size();
        for(int i=0; i<n;i++){
            indices[nums[i]].push_back(i);
        }
        int mindistance =INT_MAX;
        for(auto&pair:indices){
            vector<int>& pos=pair.second;
            if(pos.size()<3) continue;
            for(int i=0; i<pos.size()-2;i++){
                for(int j =i+1 ;j<pos.size()-1;j++){
                    for(int k =j +1; k<pos.size();k++){
                        int dist = abs(pos[i]-pos[j])+abs(pos[j]-pos[k])+abs(pos[k]-pos[i]);
                        mindistance =min(mindistance,dist);
                    }
                }
            }
        }
        return mindistance == INT_MAX?-1:mindistance;
    }
};
