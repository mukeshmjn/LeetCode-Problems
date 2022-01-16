class Solution {
public:
    void findSubsets(int idx,int& sum,vector<int>& nums,vector<vector<int>>& res,vector<int>& ds,int n){
        if(idx==n){
            res.push_back(ds);return;
        }
        ds.push_back(nums[idx]);
        findSubsets(idx+1,sum,nums,res,ds,n);
        ds.pop_back();
        findSubsets(idx+1,sum,nums,res,ds,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> res;
        int idx = 0;
        int sum =0;
        vector<int> ds;
        findSubsets(idx,sum,nums,res,ds,nums.size());
        return res;
    }
};