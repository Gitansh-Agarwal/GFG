//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    
    // code here
    sort(arr,arr+n);
    pair<int,int> p;
    int low=0,high=n-1;
    int ans=-1;
    
    //Finding the floor of the given number.
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<=x){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(ans!=-1){
        p.first=arr[ans];
    }
    else{
        p.first=ans;
    }
    
    
    //Finding the ceil of the given number.
    ans=-1;
    low=0,high=n-1;
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
    if(ans!=-1){
        p.second=arr[ans];
    }
    else{
        p.second=ans;
    }
    
    return p;
}