class Solution {
public:
       void generateAdjList(vector<vector<int>>& prerequisites,int& numCourses,vector<vector<int>>& adj,vector<int>& indegree){
       for(auto el: prerequisites){
           adj[el[1]].push_back(el[0]);
           indegree[el[0]]++;
       }
   }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> G(n);
        vector<int> degree(n, 0), bfs;
        for (auto& e : prerequisites)
            G[e[1]].push_back(e[0]), degree[e[0]]++;
        for (int i = 0; i < n; ++i) if (!degree[i]) bfs.push_back(i);
        for (int i = 0; i < bfs.size(); ++i)
            for (int j: G[bfs[i]])
                if (--degree[j] == 0) bfs.push_back(j);
        if(bfs.size()==n) return bfs;
        return {};
    }
};