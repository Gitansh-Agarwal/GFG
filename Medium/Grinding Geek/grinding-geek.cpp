//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int helper(int index, int n, int total, vector<int>&cost, vector<vector<int>>& dp){
        
        if(index == n)
            return 0;
        
        if(dp[index][total] != -1)
            return dp[index][total];
        
        int take = 0, notake = 0;
        
        notake = helper(index+1, n, total, cost, dp);
        
        if(cost[index] <= total){
            int rem = total - cost[index] + (cost[index]*9)/10;
            take = 1 + helper(index+1, n, rem, cost, dp);
        }
        
        return dp[index][total] = max(take, notake);
        
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        vector<vector<int>> dp(n+1, vector<int>(total+1, -1));
        return helper(0, n, total, cost, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends