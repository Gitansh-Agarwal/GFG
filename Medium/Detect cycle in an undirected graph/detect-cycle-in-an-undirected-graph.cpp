//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool detectCycle(int src, vector<int> adj[], int vis[]){
        vis[src]=1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto adjacentNode: adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode]=1;
                    q.push({adjacentNode, node});
                    
                }
                else if(parent != adjacentNode){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(int node, int parent, vector<int>& vis, vector<int> adj[]){
        vis[node]=1;
        
        for(auto adjacentNode:adj[node]){
            if(!vis[adjacentNode]){
                if(dfs(adjacentNode, node, vis, adj) == true){
                    return true;
                }
            }
            else if(adjacentNode!=parent){
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        //Using BFS
        //TC=O(N + 2E){BFS Traversal} + O(N){Connected Components}.
        //SC=O(N){queue} + O(N){visited array}.
        
        // int vis[V]={0};
        // for(int i=0; i<V; i++){
        //     if(!vis[i]){
        //         if(detectCycle(i, adj, vis) == true)
        //             return true;
        //     }
        // }
        // return false;
        
        
        
        //Using DFS
        //TC=O(N + 2E){dfs traversal} + O(N){for loop for connected components}
        //SC=O(N){recursion stack space} + O(N){visited array}
        
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj) == true)
                    return true;
            }
        }
        return false;
        
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends