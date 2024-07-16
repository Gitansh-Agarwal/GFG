//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int findNoOfPainters(int arr[], int n, long long int sum){
        long long int noOfPainters=1;
        long long int total=0;
        
        for(int i=0; i<n; i++){
            if(total+arr[i] <= sum){
                total+=arr[i];
            }
            else{
                noOfPainters++;
                total=arr[i];
            }
        }
        return noOfPainters;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        
        
        long long int low=*max_element(arr, arr+n);
        long long int high=0;
        for(int i=0; i<n; i++)  high+=arr[i];
        int ans=-1;
        
        while(low<=high){
            long long int mid = low + (high-low)/2;
            long long int painters = findNoOfPainters(arr, n, mid);
            if(painters <= k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
            
            //OR
            // if(painters > k){
            //     low=mid+1;
            // }
            // else{
            //     high=mid-1;
            // }
        }
        // return ans;//This is not working because when no of splits are less than required always
        // then it gives -1, which is not the answer and is also not possible.
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends