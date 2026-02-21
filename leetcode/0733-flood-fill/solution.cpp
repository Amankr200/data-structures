class Solution {
private:
void dfs(vector<vector<int>>& ans,vector<vector<int>>& image, int delRow[], int delCol[],int sr, int sc, int color,int oldcolor){
      ans[sr][sc] = color;
    int n=image.size();
    int m = image[0].size();
    for(int i=0;i<4;i++){
        int nrow= sr + delRow[i];
        int ncol= sc + delCol[i];
        if(nrow>=0 && ncol >=0 && nrow<n && ncol<m && image[nrow][ncol]==oldcolor && ans[nrow][ncol]!=color){
            dfs(ans, image, delRow,delCol,nrow, ncol,color,oldcolor);
        }
    }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc];
        vector<vector<int>> ans =image;
        int delRow[4]={1,-1,0,0};
        int delCol[4]={0,0,-1,1};
        dfs(ans, image, delRow,delCol,sr, sc,color,oldcolor);
        return ans;
    }
};
