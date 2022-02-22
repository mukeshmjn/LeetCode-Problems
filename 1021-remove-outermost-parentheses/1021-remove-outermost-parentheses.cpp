class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
int o =0;        for(char c: s){
          if(c=='('&&o++>0) res.push_back(c);
        else if(c==')'&&o-->1) res.push_back(c);
        }
        return res;
    }
};