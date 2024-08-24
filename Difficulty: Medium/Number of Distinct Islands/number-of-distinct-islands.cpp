//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        void dfs(int n, int m, int baseRow, int baseCol, int row, int col, 
        vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& vec, 
        int delRow[], int delCol[]){
            vec.push_back({row-baseRow, col-baseCol});
            vis[row][col]=1;
            
            for(int i=0; i<4; i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m 
                && grid[nRow][nCol]==1 && !vis[nRow][nCol]){
                    dfs(n, m, baseRow, baseCol, nRow, nCol, grid, vis, vec, delRow, delCol);
                }
            }
        }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int, int>>> st;
        // int vis[n][m]={0};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[]={-1, 0, +1, 0};
        int delCol[]={0, +1, 0, -1};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vector<pair<int, int>> vec;
                    dfs(n, m, i, j, i, j, grid, vis, vec, delRow, delCol);
                    st.insert(vec);
                }
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends