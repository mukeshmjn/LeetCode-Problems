class Solution {
public:

int DPnumSquares(vector<int>& Coins , vector<vector<int>>& DP , int n)
{
    // 0 th Row
    for(int i=0 ; i<Coins.size(); i++)
    {
        DP[i][0] = 0;
    }
    
    // 0 th Column
    for(int j=1 ; j<=n ; j++)
    {
        DP[0][j] = j;
    }
    
    for(int i=1 ; i<Coins.size() ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            if(j >= Coins[i])
            {
                // Check above and left
                DP[i][j] = min(DP[i-1][j] , 1+ DP[i][j- Coins[i]]);
            }
            else
            {
                // Take value from above cell
                DP[i][j] = DP[i-1][j];
            }
        }
    }
    return DP[Coins.size()-1][n];
}
int numSquares(int n) {
    // Similar to Coin change Problem
    vector<int>Coins;
    
    for(int i=1 ; i*i<=n ; i++)
    {
        Coins.push_back(i*i);
    }
    // A bag of perfect square numbers till n
    
    // 2-D DP solution
    
    vector<vector<int>> DP(Coins.size() , vector<int>(n+1, INT_MIN));
    
    return DPnumSquares(Coins , DP , n);
    
    
    
   
    
}
};