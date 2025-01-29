//{ Driver Code Starts
// Initial Template for C++

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int power(int num, int powerOnNum){
        if(powerOnNum == 0){
            return 1;
        }
        int result = num;
        for(int i=0; i<powerOnNum-1; i++){
            result*=num;
        }
        return result;
    }
    int countNodes(int i) {
        // your code here
        return power(2, i-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int i;
        cin >> i;
        Solution ob;
        int res = ob.countNodes(i);

        cout << res;
        cout << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends