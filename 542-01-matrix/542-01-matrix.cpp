class Solution {
public:
     bool isvalid(int i,int j,int m,int n)
    {
        if(i==m||j==n||j<0||i<0)
            return false;
        return true;
    }
            vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
    int n = mat[0].size();
        queue<pair<int,int>> q;

          vector<vector<int>> res(m,vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    res[i][j] = 0; 
                }
                // else res[i][j] = 2;
            }
        }
            while(!q.empty()){
                pair<int,int> cur = q.front();q.pop();
                for(auto& x: dir){
                    int a = cur.first+x[0];
                    int b = cur.second+x[1];
                    if(isvalid(a,b,m,n)&&res[a][b] == INT_MAX){
                        q.push({a,b});
                        res[a][b] = res[cur.first][cur.second]+1;
                    }
                }
            }
        
        return res;
    }
};
// class Solution {
// public:
    
    
//     bool isvalid(int i,int j,int m,int n)
//     {
//         if(i==m||j==n||j<0||i<0)
//             return false;
//         return true;
//     }
    
//     vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};
//     vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
//     {
//         queue<pair<int,int>> q;
//         int m=matrix.size();
//         int n=matrix[0].size();
//         vector<vector<int>> dis(m,vector<int>(n,-1));
//         for(int i=0;i<m;i++)
//             for(int j=0;j<n;j++)
//             {
//                 if(matrix[i][j]==0)
//                 { 
//                     q.push({i,j});
//                     dis[i][j]=0;
//                 }
//             }
//         while(!q.empty())
//         {
//             pair<int,int> curr=q.front();
//             q.pop();
//             for(auto& x:dir)
//             {
//                 int a=curr.first+x[0];
//                 int b=curr.second+x[1];
//                 if(isvalid(a,b,m,n)&&dis[a][b]==-1)
//                 {
//                     q.push({a,b});
//                     dis[a][b]=dis[curr.first][curr.second]+1;
//                 }
//             }
//         }
//         return dis;
//     }
// };