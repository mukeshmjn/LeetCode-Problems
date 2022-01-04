// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        // vector<int> vis(V+1,0);
        // vector<int> res;
        // for(int i=0;i<=V;i++){
        //     if(!vis[i]){
        //         queue<int> q;
        //         q.push(i);
        //         vis[i] = 1;
        //         while(!q.empty()){
        //             int node= q.front();
        //             q.pop();
        //             res.push_back(node);
        //             for(int it : adj[node]){
        //                 if(!vis[it]){
        //                     q.push(it);
        //                     vis[it]=1;
        //                 }
        //             }
        //         }
        //     }
        // }
        // return res;
           queue<int> q;
        q.push(0);
        vector<int> res;
        bool vis[V];
        vis[0]=1;
        for(int i=0;i<V;i++)
        vis[i]=0;
        while(!q.empty()){
            int nd = q.front();
            q.pop();
             res.push_back(nd);
            for(auto it: adj[nd])
            if(!vis[it]){
                vis[it]=1;
                 q.push(it);
            }
              
            
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends