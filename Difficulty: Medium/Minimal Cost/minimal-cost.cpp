//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    
  //Normal Recursion
    // int f(vector<int>&arr, int ind, int k){
    //     if(ind == 0)
    //         return 0;
            
    //     int mini = INT_MAX;
    //     for(int i= 1; i<=k; i++){
    //         if((ind-i) >= 0)
    //             mini = min(mini, f(arr, ind-i, k) + abs(arr[ind] - arr[ind-i]));
    //     }
        
    //     return mini;
    // }
    
    
    //Using Memoization.
    int f1(vector<int>&arr, int dp[], int ind, int k){
        if(ind == 0)
            return dp[ind] = 0;
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        int mini = INT_MAX;
        for(int i= 1; i<=k; i++){
            if((ind-i) >= 0)
                mini = min(mini, f1(arr, dp, ind-i, k) + abs(arr[ind] - arr[ind-i]));
        }
        
        return dp[ind] = mini;
    }
  public:
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        //Normal Recursion.
        // int n=arr.size();
        // return f(arr, n-1, k);
        
        
        
        //Using Memoization.
        int n = arr.size();
        int dp[n];
        memset(dp, -1, sizeof(dp));
        
        f1(arr, dp, n-1, k);
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends