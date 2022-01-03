class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,pair<int,int>>> maxH;
        for(int i=0;i<n;i++){
            maxH.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            if(maxH.size()>k) maxH.pop();
        }
        vector<vector<int>> res;
        while(!maxH.empty()){
            res.push_back({maxH.top().second.first,maxH.top().second.second});
            maxH.pop();
        }
        return res;
    }
};