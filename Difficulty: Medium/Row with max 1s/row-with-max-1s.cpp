//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int lowerBound(vector<int> arr, int n, int x){
        int low=0;
        int high=n-1;
        int ans=n;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr[mid]>=x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        //Using Kind of linear search.
        //TC=O(N*M).
        //SC=O(1).
        
        // int n=arr.size();
        // int m=arr[0].size();
        // int maxOnes=0;
        // int maxOnesRowsInd=-1;
        // for(int i=0; i<n; i++){
        //     int cntOne=0;
        //     for(int j=0; j<m; j++){
                // if(arr[i][j]==1)   cntOne++;
                //OR
                // cntOne+=arr[i][j];
        //     }
        //     if(cntOne>maxOnes){
        //         maxOnes=cntOne;
        //         maxOnesRowsInd=i;
        //     }
        // }
        // return maxOnesRowsInd;
        
        
        //TC=O(N* log2(M)).
        //SC=O(1).
        int n=arr.size();
        int m=arr[0].size();
        int maxOnes=0;
        int index=-1;
        for(int i=0; i<n; i++){
            int cntOnes= m - lowerBound(arr[i], m, 1);
            if(cntOnes>maxOnes){
                maxOnes=cntOnes;
                index=i;
            }
        }
        return index;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends