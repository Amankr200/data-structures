class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = -1;
        int maxArea = -1;
        
        for (auto &rect : dimensions) {
            int l = rect[0];
            int w = rect[1];
            
            int diagSq = l*l + w*w;  // diagonal squared
            int area = l * w;
            
            if (diagSq > maxDiag) {
                maxDiag = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiag) {
                maxArea = max(maxArea, area);
            }
        }
        
        return maxArea;
    }
};

