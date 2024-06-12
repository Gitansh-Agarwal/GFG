//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int numberContains4(int n){
        int temp=0;
        while(n!=0){
            if(n%10==4){
                temp=1;
                break;
            }
            n=n/10;
        }
        return temp;
    }
    int countNumberswith4(int n) {
        // code here
        int cnt=0;
        for(int i=4; i<=n; i++){
            cnt+=numberContains4(i);
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends