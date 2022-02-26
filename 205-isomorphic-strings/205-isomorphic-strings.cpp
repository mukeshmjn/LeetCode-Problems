class Solution {
public:
    bool helper(string s,string t){
         int n = s.length();
        map<char,char> mp;
        for(int i=0;i<n;i++){
            if(mp.count(s[i])){
            if(mp[s[i]]!=t[i]) return false;
            } else mp[s[i]] = t[i];
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        return helper(s,t) && helper(t,s);
       
    }
};