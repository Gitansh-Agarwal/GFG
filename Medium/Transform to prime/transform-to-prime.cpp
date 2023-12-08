//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    
    bool isPrimeNumber(int num){
        if(num==1)
            return false;
        for(int i=2; i<=sqrt(num); i++){
            if(num%i == 0){
                return false;
            }
        }
        return true;
    }
    int minNumber(int arr[],int N)
    {
        int sum=0;
        for(int i=0; i<N; i++){
            
            sum+=arr[i];
        }
        for(int i=sum ; i<=2*sum ; i++){
            
            if(isPrimeNumber(i)) 
                return i-sum;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends