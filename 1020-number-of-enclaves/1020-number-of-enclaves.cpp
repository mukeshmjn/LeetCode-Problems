class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[0][i]==1) dfs(grid,0,i,m,n);
            if(grid[m-1][i]==1) dfs(grid,m-1,i,m,n);
        } 
         for(int i=0;i<m;i++){
            if(grid[i][0]==1) dfs(grid,i,0,m,n);
            if(grid[i][n-1]==1) dfs(grid,i,n-1,m,n);
        }
        int res=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) res++;
            }
        return res;
    }
    
      private: 
        void dfs(vector<vector<int>>& g,int i,int j,int m,int n){
            if(i>=m || j>=n || i<0 || j<0 || g[i][j]!=1) return;
            g[i][j]=0;
            dfs(g,i+1,j,m,n);dfs(g,i-1,j,m,n);
            dfs(g,i,j+1,m,n);dfs(g,i,j-1,m,n);
            
        }
};