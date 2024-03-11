//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    //we are using BFS traversal as we have to find out the minimum distance 
	    //TC=O(N*M){filtering out all 1's into the queue} + O(N*M){queue traversal till it's not empty}.
	    //SC=O(N*M){visited} + O(N*M){dist(ans)} + O(N*M){queue}.
	   // int n=grid.size();
	   // int m=grid[0].size();
	   // vector<vector<int>> vis(n, vector<int>(m, 0));
	   // vector<vector<int>> dist(n, vector<int>(m, 0));
	   // queue<pair<pair<int, int>, int>> q;
	    
	   // //N*M = filtering out all 1's into the queue.
	   // for(int i=0; i<n; i++){
	   //     for(int j=0; j<m; j++){
	   //         if(grid[i][j] == 1){
	   //             vis[i][j] = 1;
	   //             q.push({{i, j}, 0});
	   //         }
	   //         else{
	   //             vis[i][j]=0;
	   //         }
	   //     }
	   // }
	    
	   // int delRow[]={-1, 0, +1, 0};
	   // int delCol[]={0, +1, 0, -1};
	   // while(!q.empty()){
	   //     int row = q.front().first.first;
	   //     int col = q.front().first.second;
	   //     int steps = q.front().second;
	   //     q.pop();
	   //     dist[row][col] = steps;
	        
	   //     for(int i=0; i<4; i++){
	   //         int nrow = row+delRow[i];
	   //         int ncol = col+delCol[i];
	            
	   //         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0){
	   //             vis[nrow][ncol] = 1;
	   //             q.push({{nrow, ncol}, steps+1});
	   //         }
	   //     }
	   // }
	   // return dist;
	   
	   
	   
	   
	   
	   
	   
	   
	   int n = grid.size(); 
	    int m = grid[0].size(); 
	    // visited and distance matrix
	    vector<vector<int>> vis(n, vector<int>(m, 0)); 
	    vector<vector<int>> dist(n, vector<int>(m, 0)); 
	    // <coordinates, steps>
	    queue<pair<pair<int,int>, int>> q; 
	    // traverse the matrix
	    for(int i = 0;i<n;i++) {
	        for(int j = 0;j<m;j++) {
	            // start BFS if cell contains 1
	            if(grid[i][j] == 1) {
	                q.push({{i,j}, 0}); 
	                vis[i][j] = 1; 
	            }
	            else {
	                // mark unvisited 
	                vis[i][j] = 0; 
	            }
	        }
	    }
	    
	    int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 
	    
	    // traverse till queue becomes empty
	    while(!q.empty()) {
	        int row = q.front().first.first; 
	        int col = q.front().first.second; 
	        int steps = q.front().second; 
	        q.pop(); 
	        dist[row][col] = steps; 
	        // for all 4 neighbours
	        for(int i = 0;i<4;i++) {
	            int nrow = row + delrow[i]; 
	            int ncol = col + delcol[i]; 
	            // check for valid unvisited cell
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
	            && vis[nrow][ncol] == 0) {
	                vis[nrow][ncol] = 1; 
	                q.push({{nrow, ncol}, steps+1});  
	            }
	        }
	    }
	    // return distance matrix
	    return dist; 
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends