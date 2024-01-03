//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        vector<int> freq(3, 0);
        int l=0;
        int r=0;
        int ans = 1e6;
        bool ok = 0;
        
        while(r < S.size() || r-l>=3){
            if(!ok && r<S.size()){
                ++freq[S[r++] - '0'];
                
                if(freq[0] && freq[1] && freq[2])
                    ok = 1;
                else
                    ok = 0;
            }
            else if(r-l >= 3){
                --freq[S[l++] - '0'];
                
                if(freq[0] && freq[1] && freq[2])
                    ok = 1;
                else
                    ok = 0;
            }
            
            if(ok)
                ans = min(ans, r-l);
        }
        return ans == 1e6 ? -1 : ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends