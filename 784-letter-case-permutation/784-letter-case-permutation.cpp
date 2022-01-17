class Solution {
public:
    
    void backtrack(int p, vector<string> &ans, string s, string &S){
        if(S.size()==s.size()){ // if our temporary array size is equal to input size, we have our answer
            ans.push_back(s);
            return;
        }
        for(int i=p;i<S.size();i++){
            if(isalpha(S[i])){ // if the element is alphabet, we will have to push it as uppercase as well as lowercase and then pop also as we have done in every problem till now
                s.push_back(tolower(S[i]));
                backtrack(i+1, ans, s, S);
                s.pop_back();
                s.push_back(toupper(S[i]));
                backtrack(i+1, ans, s, S);
                s.pop_back();
            }
            else{ // if it's a digit, we just have to push it to our temporary array and backtrack and pop off
                s.push_back(S[i]);
                backtrack(i+1, ans, s, S);
                s.pop_back();
            }
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        string s="";
        vector<string> ans;
        backtrack(0, ans, s, S);
        return ans;
    }
};