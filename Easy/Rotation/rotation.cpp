//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    //TC=O(N).
	   // int count=0;
	   // int i=0;
	   // while(arr[i]<arr[(i+1)%n]){
	   //     count++;
	   //     i++;
	   // }
	   // return (i+1)%n;
	   
	   
	   //TC=O(logn)
        int low=0;
        int high=n-1;
        int ans=INT_MAX;
        int index=-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            //search space is already sorted, then arr[low] will always be the smallest in that search space
            if(arr[low]<=arr[high]){
                if(arr[low]<ans){
                    ans=arr[low];
                    index=low;
                }
                break;
            }
            
            //otherwise either one of the left or right half is sorted.
            //left half is sorted
            if(arr[low]<=arr[mid]){
                if(arr[low]<ans){
                    ans=arr[low];
                    index=low;
                }
                low=mid+1;
            }            
            //right half is sorted
            else if(arr[mid]<=arr[high]){
                if(arr[mid]<ans){
                    ans=arr[mid];
                    index=mid;
                }
                high=mid-1;
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
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends