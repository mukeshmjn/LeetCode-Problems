class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res,n,n,"");
        return res;
    }
    void helper(vector<string>& res,int l, int r, string output){
        if(l==0 && r==0){
            res.push_back(output);return;
        }
        if(l!=0) helper(res,l-1,r,output+"(");
        if(r>l) helper(res,l,r-1,output+")");
    }
};