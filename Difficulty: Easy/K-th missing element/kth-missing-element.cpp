//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    int low=0;
    int high=n-1;
    
    while(low<=high){
        int mid=(low+high)/2;
        int missing = a[mid] - (a[0]+mid);
        
        if(missing < k){
            low=mid+1;
        }  
        else{
            high=mid-1;
        }
    }
    if(low==n)
        return -1;
    return high+a[0]+k;//or return low+k;
}