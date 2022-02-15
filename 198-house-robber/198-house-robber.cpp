class Solution {
public:
     int memo[108] ;
    int solve(vector<int>& nums , int n){
        if(n == 0 ) return nums[0] ;
        if(n==1) return max(nums[0], nums[1]);
        if(memo[n] != -1) return memo[n] ;
        int ans = max(solve(nums , n-1) , nums[n] + solve(nums,n-2));
        memo[n] = ans ; 
        return ans ;
    }
    int rob(vector<int>& nums) {
        memset(memo , -1 , sizeof(memo));
        int ans =solve(nums , nums.size()-1);
        return ans ; 
    }
};