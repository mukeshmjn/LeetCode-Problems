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
    void unionfun(int u,int v){
        u = findParent(u);
        v = findParent(v);
        if(u==v) return;
        par[u] = v;
        // return true;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
          int sz = connections.size();
        if(n-1>sz) return -1;
        par.resize(n);
         //initialising parents
        makeSet(n);
        // int cnt=0;
        for(int i=0;i<sz;i++){
                unionfun(connections[i][0],connections[i][1]);
        }
        int cnt=0;
        for(int i=0;i<n;i++) if(par[i]==i) cnt++;
        return cnt-1;
    }
};