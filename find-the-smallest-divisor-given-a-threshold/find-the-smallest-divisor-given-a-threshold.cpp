class Solution {
public:
    int check(vector<int>& nums,int d){
    long long int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%d==0) sum+=(nums[i]/d);
            else sum+=(nums[i]/d)+1;
            
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = 1e6;
        int res;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(nums,mid)>threshold) l = mid+1;
            else res=mid,r = mid-1;
        }
        return res;
    }
};