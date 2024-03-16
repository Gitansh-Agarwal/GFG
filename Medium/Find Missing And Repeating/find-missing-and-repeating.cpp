//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        long long Sn, S2n;
        Sn = ((long long)n*(long long)(n+1))/2;
        S2n = ((long long)n * (long long)(n+1) * (long long)(2*n+1))/6;
        
        long long S=0, S2=0;
        for(int i=0; i<n; i++){
            S += arr[i];
            S2 += (long long)arr[i]*(long long)arr[i];
        }
        
        long long val1 = S-Sn;//x-y
        long long val2 = S2-S2n;//x^2-y^2
        val2=val2/val1;//x+y
        
        long long x=(val1+val2)/2;
        long long y=x-val1;//or y=val2-x
        
        return {(int)x, (int)y};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends