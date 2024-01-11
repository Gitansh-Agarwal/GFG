//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        int n = S.length();
        if(n == K)
            return "0";
        
        stack<char> store;//Stack named store
        for(int i=0; i<n; i++){
            while(K && !store.empty() && store.top()>S[i]){
                store.pop();
                K--;
            }
            store.push(S[i]);
        }
        
        while(K){
            store.pop();
            K--;
        }
        string ans = "";
        while(!store.empty()){
            ans.push_back(store.top());
            store.pop();
        }
        
        reverse(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++){
            if(ans[i]!='0')
                return ans.substr(i);
        }
        return "0";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends