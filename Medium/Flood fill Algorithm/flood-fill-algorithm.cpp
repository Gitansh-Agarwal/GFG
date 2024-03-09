//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void dfs(int row, int col, vector<vector<int>>&ans,
     vector<vector<int>>& image, int newColor, int delRow[], int delCol[],
     int iniColor) {
        // color with new color
        ans[row][col] = newColor; 
        int n = image.size();
        int m = image[0].size(); 
        // there are exactly 4 neighbours
        for(int i = 0;i<4;i++) {
            int nrow = row + delRow[i]; 
            int ncol = col + delCol[i]; 
            // check for valid coordinate 
            // then check for same initial color and unvisited pixel
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor); 
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        //Using BFS
        //TC=O(N*M) as for X nodes, x dfs calls are made + for each of x nodes loop runs for 4 times
        // which is x+x*4 = O(x) = O(N*M).
        //SC=O(N*M).
        // int n=image.size();
        // int m=image[0].size();
        
        // queue<pair<int, int>> q;
        // vector<vector<int>> ans=image;
        // int initialValue=image[sr][sc];
        // q.push({sr,sc});
        
        // int drow[]={-1, 0, +1, 0};
        // int dcol[]={0, +1, 0, -1};
        // while(!q.empty()){
        //     int r=q.front().first;
        //     int c=q.front().second;
            
        //     ans[r][c]=newColor;
        //     q.pop();
        //     for(int i=0; i<4; i++){
        //         int nrow=r+drow[i];
        //         int ncol=c+dcol[i];
                
        //         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=newColor && image[nrow][ncol]==initialValue){
        //             q.push({nrow, ncol});
        //         }
        //     }
        // }
        // return ans;
        
        
        
        //Using DFS
        // get initial color
        int iniColor = image[sr][sc]; 
        vector<vector<int>> ans = image; 
        // delta row and delta column for neighbours
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor); 
        return ans; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends