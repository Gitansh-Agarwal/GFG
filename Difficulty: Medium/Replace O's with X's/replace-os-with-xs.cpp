//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    void dfs(int m, int n, int row, int col, vector<vector<char>>&mat, vector<vector<int>>&vis, int delRow[], int delCol[]){
        vis[row][col]=1;
        
        for(int i=0; i<4; i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            
            if(nRow>=0 && nRow<m && nCol>=0 && nCol<n){
                if(mat[nRow][nCol]=='O' && vis[nRow][nCol]==0){
                    dfs(m, n, nRow, nCol, mat, vis, delRow, delCol);
                }
            }
            
        } 
    }
    void dfs2(int m, int n, int row, int col, vector<vector<char>>&mat, vector<vector<int>>&vis, vector<vector<char>>&ans, int delRow[], int delCol[]){
        ans[row][col]='O';
        vis[row][col]=1;
        
        for(int i=0; i<4; i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            
            if(nRow>=0 && nRow<m && nCol>=0 && nCol<n){
                if(mat[nRow][nCol]=='O' && vis[nRow][nCol]==0){
                    dfs2(m, n, nRow, nCol, mat, vis, ans, delRow, delCol);
                }
            }
            
        } 
    }
public:
    //for matrix of size as m*n and not as n*m.
    vector<vector<char>> fill(int m, int n, vector<vector<char>> mat)
    {
        // code here
         //TC=O(2m+2n) + O(dfs traversal)
        // int m=mat.size();
        // int n=mat[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int delRow[]={-1, 0, +1, 0};
        int delCol[]={0, +1, 0, -1};
        //Traversing through 1st row.
        for(int i=0; i<n; i++){
            if(mat[0][i]=='O'){
                dfs(m, n, 0, i, mat, vis, delRow, delCol);
            }
        }
        //Traversing through last row.
        for(int i=0; i<n; i++){
            if(mat[m-1][i]=='O'){
                dfs(m, n, m-1, i, mat, vis, delRow, delCol);
            }
        }
        //Traversing through 1st column.
        for(int i=1; i<m-1; i++){
            if(mat[i][0]=='O'){
                dfs(m, n, i, 0, mat, vis, delRow, delCol);
            }
        }
        //Traversing through last column.
        for(int i=1; i<m-1; i++){
            if(mat[i][n-1]=='O'){
                dfs(m, n, i, n-1, mat, vis, delRow, delCol);
            }
        }
        
        
        
        
        //Travesing the entire matrix mat and making all the O's which are unvisited as X's.
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]=='O' && vis[i][j]==0){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
        
        
        
        // int m=mat.size();
        // int n=mat[0].size();
        // vector<vector<char>> ans(m, vector<char>(n, 'X'));
        // vector<vector<int>> vis(m, vector<int>(n, 0));
        //  int delRow[]={-1, 0, +1, 0};
        // int delCol[]={0, +1, 0, -1};
        // //Traversing through 1st row.
        // for(int i=0; i<n; i++){
        //     if(mat[0][i]=='O'){
        //         dfs2(m, n, 0, i, mat, vis, ans, delRow, delCol);
        //     }
        // }
        // //Traversing through last row.
        // for(int i=0; i<n; i++){
        //     if(mat[m-1][i]=='O'){
        //         dfs2(m, n, m-1, i, mat, vis, ans, delRow, delCol);
        //     }
        // }
        // //Traversing through 1st column.
        // for(int i=1; i<m-1; i++){
        //     if(mat[i][0]=='O'){
        //         dfs2(m, n, i, 0, mat, vis, ans, delRow, delCol);
        //     }
        // }
        // //Traversing through last column.
        // for(int i=1; i<m-1; i++){
        //     if(mat[i][n-1]=='O'){
        //         dfs2(m, n, i, n-1, mat, vis, ans, delRow, delCol);
        //     }
        // }
        // mat=ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends