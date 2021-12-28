// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int i=0,j=0,sum=0,res=INT_MAX;
//         while(j<nums.size()){
//             if(nums[i]==target) return 1;
//             if(sum<target) {
//             sum+=nums[j];
            
//                            if(sum==target)
//                {cout<<i<<j;         res = min(res,j-i);}
//                     j++;
//             }
//             else{
//                 if(sum==target)
//                            {//cout<<i<<j<<sum;
//                     res = min(res,j-i-1);}
                
//                 sum-=nums[i];
         
//                                   i++;
//             }

//         }
//         return res==INT_MAX?0:res;
//     }
// };
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start=0, end=0;
        int minLen=INT_MAX, sum=0;
        while(end<nums.size()){
            if(sum<s) sum+=nums[end];
            end++;
            while(sum>=s){
                if(end-start<minLen)
                    minLen=end-start;
                sum-=nums[start];
                start++;
            }
        }
        return minLen==INT_MAX ? 0 : minLen;
    }
};