class Solution {
public:
    int firstUniqChar(string s) {
        int ans = INT_MAX;
        if(s.length()==0) return -1;
        map<char,pair<int,int>> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]].first++;
            mp[s[i]].second = i;
        }
        for(auto m: mp){
            if(m.second.first==1) ans = min(ans,m.second.second);
        }
        return ans!=INT_MAX?ans:-1;
    }
};