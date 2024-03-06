//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        //SC=O(2* N*M)
        //TC=O(N*M){queue} + O(N*M*4){every node we are checking its adjacent neighbours}
        
        int n=grid.size();
        int m=grid[0].size();
        
        //n*m -> space
        queue<pair< pair<int, int>, int>> q;
        
        int vis[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        
        int tm=0;//maximum time
        int drow[] ={-1, 0, +1, 0};
        int dcol[] ={0, +1, 0, -1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm = max(tm, t);
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow= r+drow[i];
                int ncol= c+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1)                 {
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        
        // traversing in the visited array to check if there is an orange that is not rotten and is 
        // actually a fresh orange i.e. it is not an empty cell actually.
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends