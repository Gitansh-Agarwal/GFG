//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findNoOfSplits(int arr[], int N, int sum){
        int noOfSplits=1;
        int total=0;
        
        for(int i=0; i<N; i++){
            if(total+arr[i] <= sum){
                total+=arr[i];
            }
            else{
                noOfSplits++;
                total=arr[i];
            }
        }
        return noOfSplits;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        //below if statement not required.
        if(K>N){
            return -1;
        }
        
        
        int low=*max_element(arr, arr+N);
        int high=accumulate(arr, arr+N, 0);
        int ans=-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            int splits = findNoOfSplits(arr, N, mid);
            // if(splits == k){
            //     ans=mid;
            //     high=mid-1;
            // }
            // else if(splits > k){
            //     low=mid+1;
            // }
            // else{
            //     high=mid-1;
            // }
            
            //OR
            if(splits > K){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        // return ans;//This is not working dont know
         return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends