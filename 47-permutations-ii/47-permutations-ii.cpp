class Solution {
public:
    void find(vector<int>& nums,vector<int>& ds,bool freq[],vector<vector<int>>& res){
        if(ds.size()==nums.size()){
            res.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                if(i>0&&nums[i]==nums[i-1]&&!freq[i-1]) continue;
                freq[i] = 1;
                ds.push_back(nums[i]);
                find(nums,ds,freq,res);
                ds.pop_back();
                freq[i]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ds;
       // for(int i=0;i<nums.size();i++) freq[i]=0;
        bool freq[nums.size()];
           for(int i=0;i<nums.size();i++) freq[i]=0;
        vector<vector<int>> res;
        find(nums,ds,freq,res);
        return res;
    }
};