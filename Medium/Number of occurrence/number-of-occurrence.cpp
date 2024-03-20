//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	int startPos(int arr[], int n, int target){
        int ans=-1;
        // int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(arr[mid]>target){
                // low=mid+1;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int endPos(int arr[], int n, int target){
        int ans=-1;
        // int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(arr[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    pair<int, int> firstAndLastPosition(int arr[], int n, int k)
    {
        // Write your code here
        int first=startPos(arr, n, k);
        if(first==-1)  return {-1, -1};
        int last=endPos(arr, n, k);
        return {first, last};
    }

	int count(int arr[], int n, int x) {
	    // code here
	   // vector<int> v(std::begin(arr), std::end(arr));
	   //vector<int> v(arr, arr + (sizeof(arr)/sizeof(arr[0])));
	    pair<int, int> ans=firstAndLastPosition(arr, n, x);
    	if(ans.first==-1)
    		return 0;
    	return ans.second-ans.first+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends