//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    // bool bfs(int src, vector<int> adj[],int vis[]){
    //     vis[src]=1;
    //     queue<pair<int, int>> q;
    //     q.push({src, -1});
        
    //     while(!q.empty()){
    //         int node= q.front().first;
    //         int parent=q.front().second;
            
    //         for(auto adjacentNode: adj[node]){
    //             if(!vis[adjacentNode]){
    //                 vis[adjacentNode]=1;
    //                 q.push({adjacentNode, node});
    //             }
    //             else if(parent != adjacentNode){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
        
    // }
    
    
    
    bool dfs(int src, int parent, vector<int> adj[], int vis[]){
        vis[src]=1;
        
        for(auto adjacentNode: adj[src]){
            if(!vis[adjacentNode]){
                if(dfs(adjacentNode, src, adj, vis) == true){
                    return true;
                }
            }
            else if(adjacentNode != parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        //Thought Process= If a node is visited and its not the parent node of the current 
        //node, then somebody else must have visited it otherwise how can it be visited, 
        //so there exists a cycle in the graph.
        
        //Using BFS Traversal.
        //TC=O(V){for connected components} + O(V+2E){for bfs traversal}.
        //SC=O(V){queue as it will contain at max all the vertices or nodes of the graph.}
        // int vis[V]={0};
        // for(int i=0; i<V; i++){
        //     if(!vis[i]){
        //         if(bfs(i, ))
        //         bfs(i, adj, vis);
        //     }
        // }
        
        
        
        //Using DFS Traversal.
        //TC=O(V){for connected components} + O(V+2E){for DFS Traversal}.
        //SC=O(V).{Max Recursive Stack Space as it can call for at max all the elements/nodes
        // in the graph.
            int vis[V]={0};
            for(int i=0; i<V; i++){
                if(!vis[i]){
                    if(dfs(i, -1, adj, vis) == true){
                        return true;
                    }
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