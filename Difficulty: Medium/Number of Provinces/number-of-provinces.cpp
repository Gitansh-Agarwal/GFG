//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
        void bfs(int startNode, vector<int> adj[], int vis[], queue<int> &q){
            q.push(startNode);
            vis[startNode]=1;
            
            while(!q.empty()){
                int node=q.front();
                q.pop();
                
                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
        }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code 
        vector<int> adjLs[V+1];
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1 && i!=j){
                    adjLs[i+1].push_back(j+1);
                    adjLs[j+1].push_back(i+1);
                }
            }
        }
        int vis[V+1]={0};
        int cnt=0;
        for(int i=1; i<=V; i++){
            if(!vis[i]){
                queue<int> q;
                cnt++;
                bfs(i, adjLs, vis, q);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends