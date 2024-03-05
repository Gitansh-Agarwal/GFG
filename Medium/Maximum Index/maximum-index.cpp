//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<int> prefix(n), suffix(n);
        prefix[0] = a[0];
        suffix[n-1] = a[n-1];
        
        for(int i=1; i<n; i++){
            prefix[i] = min(prefix[i-1], a[i]);
            suffix[n-i-1] = max(suffix[n-i], a[n-i-1]);
        }
        int i=0, j=0, ans=0;
        while(i<=j && j<n){
            if(prefix[i] <= suffix[j]){
                ans = max(ans, j-i);
                ++j;
            }
            else{
                ++i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends