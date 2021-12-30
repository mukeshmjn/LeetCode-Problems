class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        for(i = nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]) break;
        } i--;cout<<i;
       if(i>=0){
           int j = nums.size()-1;
           while(j>i) {   
               if(nums[j]>nums[i]) break;
               j--;}
              swap(nums[i],nums[j]);
     cout<<j;
           reverse(nums.begin()+i+1,nums.end());
       } 
        else{
            reverse(nums.begin(),nums.end());
        }
    }
};