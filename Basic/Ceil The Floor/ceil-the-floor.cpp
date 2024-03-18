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

int floor(int arr[], int n, int x){
    int ans=INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i] <= x){
            ans=max(ans, arr[i]);
        }
    }
    if(ans==INT_MIN)
        return -1;
    return ans;
}
int ceil(int arr[], int n, int x){
    int ans=INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i] >= x){
            ans=min(ans, arr[i]);
        }
    }
    if(ans==INT_MAX)
        return -1;
    return ans;
}
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    pair<int, int> p;
    p.first=floor(arr, n, x);
    p.second=ceil(arr, n, x);
    
    return p;
}