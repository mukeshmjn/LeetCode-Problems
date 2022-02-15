class Solution {
public:
    int rob(vector<int>& ar) {
        int n = ar.size();
         int dp[n+1];
    dp[0] = 0;
    dp[1] = ar[0];
    for(int i=2; i<=n; i++){
        dp[i] = max(dp[i-1], dp[i-2]+ar[i-1]);
    }
    return dp[n];
    }
};