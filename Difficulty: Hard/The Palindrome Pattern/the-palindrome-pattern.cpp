//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n=arr.size();
        //For Rows.
        for(int i=0; i<n; i++){
            int temp=1;
            int j=0;
            int k=n-1;
            while(j<k){
                if(arr[i][j]!=arr[i][k]){
                    temp=0;
                    break;
                }
                j++;
                k--;
            }
            if(temp==1){
                return to_string(i)+" R";
            }
        }
        
        //For Columns.
        for(int i=0; i<n; i++){
            int temp=1;
            int j=0;
            int k=n-1;
            while(j<k){
                if(arr[j][i]!=arr[k][i]){
                    temp=0;
                    break;
                }
                j++;
                k--;
            }
            if(temp==1){
                return to_string(i)+" C";
            }
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends