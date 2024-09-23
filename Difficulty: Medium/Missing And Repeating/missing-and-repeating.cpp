//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution { 
  private:
    int missingXorRepeating(vector<int>& arr) {
        int n = arr.size();
        int xor_all = 0;
        
        // Step 1: XOR all array elements and numbers from 1 to n
        for (int i = 0; i < n; i++) {
            xor_all ^= arr[i];
        }
        for (int i = 1; i <= n; i++) {
            xor_all ^= i;
        }
        return xor_all;
    }

  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int repeatingNum;
        for(int i=0; i<n-1; i++){
            if(arr[i] == arr[i+1]){
                repeatingNum = arr[i];
                break;
            }
        }
        int xor_all = missingXorRepeating(arr);
        return {repeatingNum, xor_all^repeatingNum};
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
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends