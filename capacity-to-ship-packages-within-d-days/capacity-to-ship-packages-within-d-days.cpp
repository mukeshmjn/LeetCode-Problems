class Solution {
public:
    bool isPossible(vector<int>& weights,int k,int days){
        int sum=0;
        int d=1;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>k) sum=weights[i],d++;
            if(d>days) return 0;
        }
        return 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=INT_MIN,r=0,res=0;
        for(int i=0;i<weights.size();i++){
            r+=weights[i];
            l = max(l,weights[i]);
        }
        cout<<l;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isPossible(weights,mid,days)){
                cout<<"mhere";
                res = mid;
                r = mid-1;
            }
            else l=mid+1;
        } 
        return res;
    }
};