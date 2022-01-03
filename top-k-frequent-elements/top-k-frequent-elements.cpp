class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;
        for(auto m: mp){
            minH.push({m.second,m.first});
            if(minH.size()>k) minH.pop();
        }
        vector<int> res;
        while(minH.size()!=0){
            res.push_back(minH.top().second);
            minH.pop();
        }
        return res;
    }
};