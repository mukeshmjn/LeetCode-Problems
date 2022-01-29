class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    res++;
                    dfs(grid,i,j,m,n);
                }
            }
        }
        return res;
    }
    private: void dfs(vector<vector<char>>& g,int i,int j,int m,int n){
        if(i<0 || j<0 || i>m-1 || j>n-1||g[i][j]!='1') return;
        g[i][j]='0';
        dfs(g,i+1,j,m,n); dfs(g,i-1,j,m,n);
         dfs(g,i,j+1,m,n); dfs(g,i,j-1,m,n);
    }
};