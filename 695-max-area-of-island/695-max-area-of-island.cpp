class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size(),lArea = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    int area = 0;
                    computeArea(i,j,grid,area);
                    if(area>lArea) lArea = area;
                }
            }
        }
        return lArea;
    }
    
    void computeArea(int i,int j,vector<vector<int>>& grid,int& area){
        int m = grid.size(),n = grid[0].size();
        if(i>=0 && j>=0 && i<m && j<n && grid[i][j]){
            area++;
            grid[i][j] = 0;
            computeArea(i+1,j,grid,area);
            computeArea(i-1,j,grid,area);
            computeArea(i,j+1,grid,area);
            computeArea(i,j-1,grid,area);
        }
    }
};