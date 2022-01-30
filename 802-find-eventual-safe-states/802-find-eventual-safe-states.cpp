class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0),res;
        for(int i=0;i<graph.size();i++)
            if(color[i]==2||!dfs(graph,color,i)) res.push_back(i);
        return res;
    }
    private: 
        bool dfs(vector<vector<int>>& graph,vector<int>& clr,int nod){
            clr[nod] = 1;
            for(auto nbr: graph[nod])
                if((clr[nbr]==0&&dfs(graph,clr,nbr)) || clr[nbr] == 1) 
                    return true;
            clr[nod] = 2;
            return false;
        }
};