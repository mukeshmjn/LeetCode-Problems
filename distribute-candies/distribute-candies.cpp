class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
    for(auto c: candyType)  s.insert(c);
        return s.size()>=candyType.size()/2?candyType.size()/2:s.size();
    }
};