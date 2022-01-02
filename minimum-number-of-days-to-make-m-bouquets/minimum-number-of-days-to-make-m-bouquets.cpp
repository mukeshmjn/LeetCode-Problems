class Solution {
public:
    int getB(vector<int>& bloomDay,int day,int k){
        int cnt=0,res=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day) cnt++;
            else cnt=0;
            if(cnt==k) res++,cnt=0;
        }
        return res;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n<m*k) return -1;
        int l,r;
        for(int i=0;i<n;i++){
            l = min(l,bloomDay[i]);
            r = max(r,bloomDay[i]);
            
        }
        int res=0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(getB(bloomDay,mid,k)<m){
                l=mid+1;
            }
            else res = mid,r=mid-1;
        }
        return res;
        
    }
};