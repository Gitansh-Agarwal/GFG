//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
     void topoSort(int node, int vis[], vector<pair<int, int>> adj[], stack<int>&st){
         vis[node] = 1;
         
         for(auto it: adj[node]){
             int v = it.first;
             
             if(!vis[v]){
                 topoSort(v, vis, adj, st);
             }
         }
         st.push(node);
     }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> adj[N];
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        //Step1 = finding the topo sort.
        //Plain DFS for finding topoSort.
        //O(N + M).
        int vis[N] = {0};
        stack<int> st;
        for(int i=0; i<N; i++){
            if(!vis[i]){
                topoSort(i, vis, adj, st);
            }
        }
        
        //Step 2 = Do the distance thing.
        vector<int> dist(N);
        for(int i=0; i<N; i++){
            dist[i] = 1e9;
        }
        dist[0] = 0;
        //starting from the source node.
        while(st.top() != 0){
            st.pop();
        }
        
        //O(N + M){N because at max the stack can have N elements and M because as we are
        // traversing through all the neighbours of all the nodes in the stack which are 
        // at most M {as M edges are there in total so M neighbours in total}.}
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if((dist[node] + wt) < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        vector<int> ans(N, -1);
        for(int i=0; i<N; i++){
            if(dist[i] != 1e9){
                ans[i] = dist[i];
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends