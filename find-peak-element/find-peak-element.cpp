class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        if(nums.size() == 1) return 0;
        int n =nums.size(),r = n-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(m>0&&m<n-1){
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1]){
                return m;
            }
            else if(nums[m-1]>nums[m]) r = m-1;
                else l=m+1;
                }
            else if(m==0){
                if(nums[m]>nums[m+1]) return 0;
                else return 1;
            }
            else if(m==n-1){
                if(nums[m]>nums[m-1]) return n-1;
                else return n-2;
            }
        }
        return -1;
    }
};