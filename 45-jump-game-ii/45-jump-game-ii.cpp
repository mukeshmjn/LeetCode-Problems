class Solution {
public:
    int jump(vector<int>& nums,int pos = 0) {
        //TLE
    //     if(pos>=nums.size()-1) return 0;
    //     int minJumps = 10001;
    //     for(int i=1;i<=nums[pos];i++)
    //         minJumps = min(minJumps,1+jump(nums,pos+i));
    // return minJumps;
        
        	int n = size(nums);
	vector<int> dp(n, 10001);
	dp[n - 1] = 0;  // start from last index. No jumps required to reach end if we are already here
	// same as above. For each index, explore all jump sizes and use the one requiring minimum jumps to reach end
	for(int i = n - 2; i >= 0; i--) 
		for(int jumpLen = 1; jumpLen <= nums[i]; jumpLen++) 
			dp[i] = min(dp[i], 1 + dp[min(n - 1, i + jumpLen)]);  // min(n-1, i + jumpLen) for bounds handling
	return dp[0];
    }
};