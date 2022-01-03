class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        priority_queue<pair<int,string>,vector<pair<int,string>>,MyComp> minH;
        int n = words.size();
        for(string w: words){
            mp[w]++;
         cout<<w<<" ";
        }
        for(auto m: mp){
          //  cout<<m.first;
            minH.push({m.second,m.first});
            minH.top().first;
            if(minH.size()>k) minH.pop();
        }
        vector<string> res;
        while(minH.size()!=0){
           // res.push_back(minH.top().second);
            res.insert(res.begin(),minH.top().second);
            minH.pop();
        }
     // sort(res.begin(),res.end());
        return res;
    }
    private:
    struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second < b.second;
            }
        }
    };
};

