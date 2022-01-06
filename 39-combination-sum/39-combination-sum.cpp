class Solution {
public:
    void findC(int ind, int t, vector<int>& ds,vector<vector<int>>& ans, vector<int>& arr){
        if(ind==arr.size()){
            if(t==0){
                ans.push_back(ds);
            }
                return;
        }
        if(arr[ind]<=t){
            ds.push_back(arr[ind]);
            findC(ind,t-arr[ind],ds,ans,arr);
            ds.pop_back();
        }
        findC(ind+1,t,ds,ans,arr);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     vector<vector<int>> ans;
        vector<int> ds;
        findC(0,target,ds,ans,candidates);
        return ans;
    }
};