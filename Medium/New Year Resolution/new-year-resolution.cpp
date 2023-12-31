//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    int helper(int i, int N, int coins[], int sum, vector<vector<int>>& dp){
        if(sum == 2024)
            return 1;
        if(sum!=0 && (sum%20 == 0 || sum%24 == 0))
            return 1;
            
        //Base Case
        if(i>=N)
            return 0;//means not possible to redeem merchandise with the current set of selected values.
            
        //checking if the value is memoized or not.
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        int take = helper(i+1, N, coins, sum+coins[i], dp);
        int notake = helper(i+1, N, coins, sum, dp);
        
        return dp[i][sum] = (take || notake);
    }
    int isPossible(int N , int coins[]) 
    {
        int sum = 0;
        for(int i=0; i<N; i++){
            sum+=coins[i];
        }
        vector<vector<int>> dp(N , vector<int>(sum+1, -1));
        return helper(0,N,coins,0,dp);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends