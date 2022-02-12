class Solution {
public:
    int integerBreak(int n) {
//         TLE::::
       //  if(n==1) return 1;
       //  int res = 0;
       //  for(int i=1;i<=n;i++){
       // auto tmp = max(i * integerBreak(n-i), i * (n -i));
       //      res = max(res, tmp);
       //  }
       //  return res;
        
        //dp
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                auto t = max(j*dp[i-j],j*(i-j));
                dp[i] = max(dp[i],t);
            }
        }
        return dp[n];
    }
};