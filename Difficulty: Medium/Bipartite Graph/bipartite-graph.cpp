//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        bool bfs(int start, vector<int> adj[], int color[]){
            color[start]=0;
            queue<int> q;
            q.push(start);
            
            while(!q.empty()){
                int node=q.front();
                q.pop();
                
                for(auto it: adj[node]){
                    //if the adjacent node is not yet coloured, we colour it with the opposite color to that of the (node).
                    if(color[it] == -1){
                        color[it] = !color[node];
                        q.push(it);
                    }
                    // the neighbour is already coloured, then check is the adjacent guy have the same colour, if yes, then someone must have coloured it on some other path. 
                    else if(color[it] == color[node]){
                        return false;
                    }
                }
            }
            return true;
        }
    
    
    bool dfs(int start, int colorVal, vector<int> adj[], int color[]){
            color[start]=colorVal;
                
            for(auto it: adj[start]){
                //if the adjacent node is not yet coloured, we colour it with the opposite color to that of the (node).
                if(color[it] == -1){

                    if(dfs(it, !color[start], adj, color) == false){
                        return false;
                    }

                }
                // the neighbour is already coloured, then check is the adjacent guy have the same colour, if yes, then someone must have coloured it on some other path. 
                else if(color[it] == color[start]){
                    return false;
                }
            }
            
            return true;
        }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    //Using BFS Traversal.
        //TC=O(N*M){BFS Traversal} + O(V){for connected components}.
        //SC=O(N*M).{queue space} + O(V){color array space}.
//         int color[V];
//         for(int i=0; i<V; i++){
//             color[i]=-1;
//         }
        
//         //for connected components.
//         for(int i=0; i<V; i++){
//             if(color[i] == -1){
//                 if(bfs(i, adj, color) == false){
//                     return false;
//                 }
//             }
//         }
//         return true;
        
        
        
        
        //Using DFS Traversal.
        //TC=O(N*M){BFS Traversal} + O(V){for connected components}.
        //SC=O(N*M).{Recursive Stack Space} + O(V){color array space}.
        int color[V];
        for(int i=0; i<V; i++){
            color[i]=-1;
        }
        
        //for connected components.
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(dfs(i, 0, adj, color) == false){
                    return false;
                }
            }
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends