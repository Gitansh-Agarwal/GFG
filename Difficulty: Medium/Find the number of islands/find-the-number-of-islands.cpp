//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
            //TC=O(N*M*9).
            vis[row][col]=1;
            queue<pair<int, int>> q;
            q.push({row, col});
            
            int n=grid.size();
            int m=grid[0].size();
            while(!q.empty()){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                
                //Traversing all the neighbours of the current node.
                for(int delRow=-1; delRow<=1; delRow++){
                    for(int delCol=-1; delCol<=1; delCol++){
                        int nRow=row+delRow;
                        int nCol=col+delCol;
                        
                        if(nRow>=0 && nRow<n && nCol>=0 && nCol<m 
                        && grid[nRow][nCol]=='1' && !vis[nRow][nCol]){
                            vis[nRow][nCol]=1;
                            q.push({nRow, nCol});
                        }
                    }
                }
            }
        }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        //Total TC=O(N*M)+O(N*M*9) = O(N*M).
        //Total SC=O(N^2){for vis} + O(N^2){for queue -> at max space} = O(N^2).
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt=0;
        
        //TC=O(N*M).
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col]=='1' && !vis[row][col]){
                    cnt++;
                    bfs(row, col, grid, vis);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends