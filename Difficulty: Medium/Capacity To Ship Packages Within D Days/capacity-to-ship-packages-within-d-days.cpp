//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int reqNoOfDays(int arr[], int n, int mid){
        int noOfDays=0;
        int capacity=mid;
        int i=0;
        while(i<n){
            if(arr[i]<=capacity){
                capacity-=arr[i];
                i++;
            }
            else{
                noOfDays++;
                capacity=mid;
            }
        }
        if(capacity!=mid){
            noOfDays++;
        }
        return noOfDays;
        
        
        //OR 
        
        
        // int reqDays=1;
        // int load=0;
        
        // for(int i=0; i<n; i++){
        //     if(load+arr[i] > capacity){
        //         reqDays++;
        //         load=arr[i];
        //     }
        //     else{
        //         load+=arr[i];
        //     }
        // }
        // return reqDays;
    }
    void findMax(int arr[], int n, int& maxi, int& sum){
        for(int i=0; i<n; i++){
            if(arr[i]>maxi){
                maxi=arr[i];
            }
            sum+=arr[i];
        }
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        // int n=arr.size();
        int maxi=INT_MIN;
        int sum=0;
        findMax(arr, n, maxi, sum);
        int low=maxi;
        int high=sum;
        int ans=-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
                if(reqNoOfDays(arr, n, mid) <= d){
                    ans=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    }
    return 0;
}
// } Driver Code Ends