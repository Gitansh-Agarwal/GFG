//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  public:
    // int LCS(string x, string y, int n, int m){
    int LCS(string x, string y, int n, int m, vector<vector<int>>&t){
        if(n==0 || m==0){
            return 0;
        }
        
        if(t[n][m]!=-1){
            return t[n][m];
        }
        if(x[n-1] == y[m-1]){
            return t[n][m]=1+LCS(x,y, n-1, m-1, t);
        }
        else {
            return t[n][m]=max(LCS(x,y, n-1, m, t) , LCS(x,y, n, m-1, t));
        }
    }
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2) {
        // your code here
         //Recursive CODE
        // return LCS(str1, str2, n, m);
        
        
        //Memoization

        //  vector<vector<int>> t(n+1, vector<int>(m+1,-1));
        
        // return LCS(str1, str2, n, m, t);
        
        
        //Top-Down Approach.
        vector<vector<int>> t(n+1, vector<int>(m+1,0));
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(str1[i-1] == str2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
};


//{ Driver Code Starts.
int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, str1, str2) << endl;
    }
    return 0;
}

// } Driver Code Ends