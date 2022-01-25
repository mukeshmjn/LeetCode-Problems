class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(),n = board[0].size();
        if(m==0) return;
        for(int i=0;i<n;i++){
                if(board[0][i]=='O') dfs(board,0,i,m,n);
                if(board[m-1][i]=='O') dfs(board,m-1,i,m,n);
        }
            for(int j=0;j<m;j++){
                if(board[j][0]=='O') dfs(board,j,0,m,n);
                if(board[j][n-1]=='O') dfs(board,j,n-1,m,n);
            }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
        
    }
    
    private: 
        void dfs(vector<vector<char>>& b,int i,int j,int m,int n){
            if(i>=m || j>=n || i<0 || j<0 || b[i][j]!='O') return;
            b[i][j]='#';
            dfs(b,i+1,j,m,n);dfs(b,i-1,j,m,n);
            dfs(b,i,j+1,m,n);dfs(b,i,j-1,m,n);
            
        }
};