//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    // Ist Method using three variables first,second,third 
	    if(n == 1)
	        return arr[0];
	    if(n == 2)
	        return max(arr[0],arr[1]);
	    if(n == 3)
	        return max(arr[1],arr[0]+arr[2]);
	    int first = arr[0];
	    int second = arr[1];
	    int third = max(second, first+arr[2]);
	    int sum;
	    int maxi_sum = max(arr[0],third);
	    for(int i=3; i<n; i++){
	        sum = max(arr[i]+first,arr[i]+second);
	        maxi_sum = max(maxi_sum , sum);
	        first = second;
	        second = third;
	        third = sum;
	    }
	    
	    return maxi_sum;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends