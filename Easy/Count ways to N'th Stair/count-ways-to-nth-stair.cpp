//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    
    // long long tempFib(int ind){
    //     if(ind==0){
    //         return 1;
    //     }
    //     if(ind==1){
    //         return 1;
    //     }
        
    //     long long left=tempFib(ind-1);
    //     long long right=tempFib(ind-2);
        
        
    //     return left+right;
    // }
    long long countWays(int n) {
        // your code here
        //This question is same is a fibonacci series solution.
        // long long dp[n+1];
        // long long ans=0;
        // ans=tempFib(n);
        
        // return ans;
        
        
        
        //Correct Solution
        long long res[n+1];
        res[0]=1;
        res[1]=1;
        
        for(int i=2;i<=n;i++){
            res[i]=res[i-2]+1;
        }
        return res[n];
    }
};

//{ Driver Code Starts.
int main() {
    // taking count of testcases
    int t;
    cin >> t;

    while (t--) {
        // taking stair count
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countWays(n) << endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends