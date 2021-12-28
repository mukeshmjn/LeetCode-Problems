class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.size();
        int i=0,j=0;
        int res=0;
        map<char,int> mp;
        while(j<n){
            if(!mp[s[j]]){
                cout<<i<<j;
                mp[s[j++]]++;
                 res = max(res,j-i);
            }
            else{
            while(mp[s[j]]){
                mp[s[i]]--;i++;
            }
            }
           
        }
        int ans=0;
        for(auto m:mp) {
        if(m.second>0) ans++;
        }
        return res;
    }
};