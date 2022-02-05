class Solution {
public:
    vector<int> par, rank;
    void makeSet(int n){
        par.resize(n+1);rank.resize(n+1);
        for(int i=1;i<=n;i++){
            par[i]=i;rank[i]=0;
        }
    }
    
    int findParent(int k){
        if(par[k]==k) return k;
        return par[k] = findParent(par[k]);
    }
    
    bool unionFun(int u,int v){
        u = findParent(u);
        v = findParent(v);
        if(u==v) return false;
        if(rank[u]>rank[v]){
            par[v] = u;
        }
        else if(rank[v]>rank[u]){
            par[u] = v;
        }else{
            par[v] = u;
            rank[u]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        makeSet(edges.size());
        for(auto e: edges){
            if(!unionFun(e[0],e[1])) return {e[0],e[1]};
        }
        return {};
    }
};