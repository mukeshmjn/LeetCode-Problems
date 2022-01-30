class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> color(n,0);
        //0->uncolored, 1->red & 2-> blue.
        for(int i=0;i<n;i++){
            if(color[i]) continue;
            color[i] =  1;
            q.push(i);
            while(!q.empty()){
                int cur = q.front();q.pop();
                for(int nbr: graph[cur]){
                    if(!color[nbr]) color[nbr] = -color[cur],q.push(nbr);
                    else if(color[nbr]==color[cur]) return false;
                }
            }
        }
        return true;
    }
};