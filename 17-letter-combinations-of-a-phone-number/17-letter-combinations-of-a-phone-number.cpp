class Solution {
public:
    void find(int st,string digits,string tempAns,map<char,string> m,vector<string>& res){
        if(digits.size()==tempAns.size()){
            res.push_back(tempAns);
            return;
        }
        for(int i=st;i<digits.size();i++){
            char c = digits[i];
            for(int j=0;j<m[c].size();j++){
                char ch = m[c][j];
                tempAns.push_back(ch);
                find(i+1,digits,tempAns,m,res);
                tempAns.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        string tempAns = "";
        int start = 0;
        map<char,string> m;
        vector<string> res;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
       // m['9'] = ""
        if(digits.size() == 0) return {};
        find(start,digits,tempAns,m,res);
        return res;
    }
};