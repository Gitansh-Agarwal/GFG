//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        long long base10Num = n;
        long long base9Num=0;
        int pos = 1;
        
        while(base10Num > 0){
            
            //taking remainder with 9.
            base9Num += pos * (base10Num%9);
            
            //dividing the number with 9.
            base10Num /= 9;
            
            //multiplying position with 10.
            pos *= 10;
        }
        
        return base9Num;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends