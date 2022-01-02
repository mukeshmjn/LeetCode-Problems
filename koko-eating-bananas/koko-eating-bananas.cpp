class Solution {
public:
    bool canEatAll(vector<int> piles,int k,int h){
        int cnt=0;
        for(int pile: piles){
            cnt+=pile/k;
            if(pile%k!=0) cnt++;
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r;
        for(int i=0;i<piles.size();i++){
            r=max(r,piles[i]);
        } int res;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(canEatAll(piles,mid,h)) res=mid,r=mid-1;
            else l=mid+1;
        }
        return res;
    }
};