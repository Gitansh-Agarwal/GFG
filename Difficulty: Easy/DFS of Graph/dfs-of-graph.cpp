//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        void dfs(int startNode, vector<int> adj[], int vis[], vector<int>& dfsTraversal){
            vis[startNode]=1;
            dfsTraversal.push_back(startNode);
            
            for(auto it: adj[startNode]){
                if(!vis[it]){
                    dfs(it, adj, vis, dfsTraversal);
                }
            }
        }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        vector<int> dfsTraversal;
        int startNode=0;
        dfs(startNode, adj, vis, dfsTraversal);
        
        return dfsTraversal;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends