class Solution {
public:
    vector<int> par;
    void makeSet(int n){
        //making every element parent of itself
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    int findParent(int k){
        if(k==par[k]) return k;
        return par[k]=findParent(par[k]);
    }
    bool unionfun(int u,int v){
        u = findParent(u);
        v = findParent(v);
        if(u==v) return false;
        par[u] = v;
        return true;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        par.resize(n);
         //initialising parents
        makeSet(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])&&unionfun(i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};