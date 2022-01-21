class Solution {
public:
    void getCoordinates(int n,int s,int& row,int& col){
        row = n-1-(s-1)/n;
        col = (s-1)%n;
        if((n%2==1&&row%2==1) || (n%2==0&&row%2==0)) col = n-1-col;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int,int>> q;
        vector<bool> vis(n*n+1,false);
        vis[1] = true;
        q.push({1,0});
        while(!q.empty()){
            pair<int,int> p = q.front();q.pop();
            int row,col,s = p.first,dist = p.second;
            
            if(s==n*n) return dist;
            for(int i=1;s+i<=n*n&&i<=6;i++){
                getCoordinates(n,s+i,row,col);
                int sFinal = board[row][col]==-1?s+i:board[row][col];
                if(!vis[sFinal]){
                    vis[sFinal] = true;
                    q.push({sFinal,dist+1});
                }
            }
        }
        return -1;
    }
};