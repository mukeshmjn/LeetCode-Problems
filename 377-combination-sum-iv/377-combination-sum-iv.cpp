class Solution {
public:
        unordered_map<int,int> m;

    int combinationSum4(vector<int>& nums, int target) {
       if(m.count(target))return m[target];
        if(target == 0)return 1;
        if(target < 0)return 0;
        for(int i=0; i<nums.size(); i++){
            m[target] += combinationSum4(nums, target-nums[i]);
        }
        return m[target];
    }
};