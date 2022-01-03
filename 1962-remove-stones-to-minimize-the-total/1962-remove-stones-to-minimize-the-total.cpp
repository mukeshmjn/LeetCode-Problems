class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        int sum=0;
        priority_queue<int> maxH;
        for(auto p: piles){
            maxH.push(p);
            sum+=p;
        }
        while(k--){
            int x = maxH.top();
            maxH.pop();
            maxH.push(x-x/2);
            sum-=x/2;
        }
        return sum;
    }
};