class Solution {
public:
         bool isvalid(int i,int j,int m,int n)
    {
        if(i==m||j==n||j<0||i<0)
            return false;
        return true;
    }
            vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        if(q.size() == m*n) return -1;
        int res = 0;
        while(!q.empty()){
            int sz = q.size();
          
            res++;
            while(sz--){
                  pair<int,int> cur = q.front();q.pop();
            for(int i=0;i<4;i++){
                int a = cur.first+dir[i][0];
                int b = cur.second+dir[i][1];
                if(isvalid(a,b,m,n)&&grid[a][b]==0){
                    q.push({a,b});
                    grid[a][b] =1;
                }
            }
        }
        }
        return res-1;
    }
};