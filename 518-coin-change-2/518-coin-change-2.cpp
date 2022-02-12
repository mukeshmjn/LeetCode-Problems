class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp;
             if(amount == 0) {
            return 1;
        }
        if(n==0)
          return 0;
        dp.resize(n+1,vector<int>(amount+1,-1));
        for(int i=1;i<=n;i++) dp[i][0] = 1;
        for(int i=1;i<=amount;i++) dp[0][i] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]>j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }
        return dp[n][amount];
    }
};