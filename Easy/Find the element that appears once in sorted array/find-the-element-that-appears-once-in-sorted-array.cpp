//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        if(n==1)
            return arr[0];
        if(arr[0]!=arr[1])  return arr[0];
        if(arr[n-1]!=arr[n-2])    return arr[n-1];
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1])
                return arr[mid];
            
            //elimination 
            
            //arr[]=[1,1,2,2,3,3,4,5,5,6,6]
            //left half = (even, odd)pairs
            //right half= (odd, even)pairs
            
            //left half
            if((mid%2==1 && arr[mid-1]==arr[mid]) || (mid%2==0 && arr[mid]==arr[mid+1])){
                low=mid+1; //eliminating left half
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends