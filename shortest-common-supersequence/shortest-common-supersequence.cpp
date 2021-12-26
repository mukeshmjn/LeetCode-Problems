class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
        int n = X.length();
        int m =Y.length();
      int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(X[i-1] == Y[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i=n,j=m;
        string s;
        while(i>0 && j>0){
            if(X[i-1] == Y[j-1]){
                s+=X[i-1];
                i--,j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                s+=X[i-1];
                i--;
            }
            else{
                s+=Y[j-1];
                j--;
            }
        }
        while(i>0){
            s+=X[i-1];
            i--;
        }
        while(j>0){
            s+=Y[j-1];
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};