class Solution {
public:
   void generateAdjList(vector<vector<int>>& prerequisites,int& numCourses,vector<vector<int>>& adj,vector<int>& indegree){
       for(auto el: prerequisites){
           adj[el[1]].push_back(el[0]);
           indegree[el[0]]++;
       }
   }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        queue<int> q;
        generateAdjList(prerequisites,numCourses,adj,indegree);
        for(int i=0;i<numCourses;i++) if(!indegree[i]) q.push(i);
        vector<int> res;
               cout<<q.front();
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for(int nbr: adj[cur]){
                indegree[nbr]--;
                if(!indegree[nbr]) q.push(nbr);
            }
        }
 
        return res.size() == numCourses;
    }
};