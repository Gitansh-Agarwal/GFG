//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // Your code here
        // Below method is taking huge amount of space, so using the below method is giving TLE Error and so it 
        // is not feasible
        // int maxElement = *max_element(arr, arr+n);
        // int requiredCount = n/k;
        // int count = 0;
        // // int *HT = new int[maxElement + 1];
        // // for(int i=0; i<maxElement+1; i++){
        // //     HT[i] = 0;
        // // }
        // vector<int> vec(maxElement+1,0);
        
        // for(int i=0; i<n; i++){
        //     vec[arr[i]]++;
        // }
        
        // for(int i=0; i<maxElement+1; i++){
        //     if(vec[i] > requiredCount){
        //         count++;
        //     }
        // }
        // return count;
        
        
        //Ist Method is to use sort function which has Time Complexity = O(NlogN);
        sort(arr, arr+n);
        int count = 1;
        int ans = 0;
        int requiredCount = n/k;
        
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]){
                count++;
            }
            else{
                if(count > requiredCount){
                    ans++;
                }
                count = 1;
            }
        }
        if(count > requiredCount){
            ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends