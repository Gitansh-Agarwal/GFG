//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    int countStudents(int arr[], int n, long long int pages){
        int students=1;
        long long pagesStudent=0;
        
        for(int i=0; i<n; i++){
            if(pagesStudent+arr[i] <= pages){
                pagesStudent+=arr[i];
            }
            else{
                students++;
                pagesStudent=arr[i];
            }
        }
        return students;
    }
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if(m>n)
        return -1;
        long long int low = *max_element(arr, arr+n);
        long long int high= accumulate(arr, arr+n, 0);
        int ans=-1;
    
        while(low<=high){
            long long int mid=(low+high)/2;
    
            long long int noOfStudents=countStudents(arr, n, mid);
            if(noOfStudents > m){
                low=mid+1;
            }
            // else if(noOfStudents < m){
            //     high=mid-1;
            // }
            // else{
            //     ans=mid;
            //     high=mid-1;
            // }
            //Or 
            else{
                high=mid-1;
            }
        }
        // return ans;//it is getting partially accepted
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends