class Solution {
public:
        vector<int> par, rank;int count=0;
    void makeSet(int n){
        count = n;
        par.resize(n);rank.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;rank[i]=0;
        }
    }
    
    int findParent(int k){
        if(par[k]==k) return k;
        return par[k] = findParent(par[k]);
    }
    
    void unionFun(int u,int v){
        u = findParent(u);
        v = findParent(v);
        if(u==v) return ;
        if(rank[u]>rank[v]){
            par[v] = u;
        }
        else if(rank[v]>rank[u]){
            par[u] = v;
        }else{
            par[v] = u;
            rank[u]++;
        }
        count--;
        // return true;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        makeSet(n);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]){
                    unionFun(i,j);
                }
            }
        }
        return count;
    }
};