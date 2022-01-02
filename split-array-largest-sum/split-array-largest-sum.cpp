class Solution {
public:
    bool isValid(vector<int>& nums,int k,int m){
            int sum=0,cnt=1;
        for(int num:nums){
            sum+=num;
            if(sum>k) sum=num,cnt++;
            if(cnt>m) return 0;
        } return 1;
    }
    int splitArray(vector<int>& nums, int m) {
        int l=0,r=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            l = max(l,nums[i]);
            r+=nums[i];
        } int res=0;cout<<l;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isValid(nums,mid,m)){
                res=mid,r=mid-1;
            // cout<<1;
            }   else l = mid+1; 
        }
        return res;
    }
};