//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        //TC=O(N*M).
        //SC=O(N*M).
    //It is an example of multi-source bfs as we are starting with more than 1 start points.
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m]={0};
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //first row, first col, last row, last col.
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        vis[i][j]=1;
                        q.push({i, j});
                    }
                }
            }
        }
        
        int delRow[]={-1, 0, +1, 0};
        int delCol[]={0, +1, 0, -1};
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            //Traversing in all 4 directions.
            for(int i=0; i<4; i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m 
                && grid[nRow][nCol]==1 && !vis[nRow][nCol]){
                    vis[nRow][nCol]=1;
                    q.push({nRow, nCol});
                }
            }
        }
        
        
        
        //Traversing the matrix. 
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    cnt++;
                }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends