class Solution {
public:
    void find(vector<int>& ds,vector<vector<int>>& res,int k,int n,int j){
        if(n==0&&ds.size()==k){
            res.push_back(ds);
            return;
        }
        for(int i=j;i<=9;i++){
            if((n-i)<0) break;
            ds.push_back(i);
            find(ds,res,k,n-i,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<int> ds;
        vector<vector<int>> res;
        int j=1;
        find(ds,res,k,n,j);
        return res;
           
    }
};