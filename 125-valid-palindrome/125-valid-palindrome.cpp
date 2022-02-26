class Solution {
public:
    bool isPalindrome(string S) {
        string s="";
        for(char c: S) if(isalpha(c) || isdigit(c) ) {
            if(isalpha(c))
            s+=tolower(c);
            if(isdigit(c)) s+=c;
        }
        int n = s.length();
        // if(s.length()==1) return false;
        // if(s.length()==0) return true;
        for(int i=0;i<s.length()/2;i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }
};