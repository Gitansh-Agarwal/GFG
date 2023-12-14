//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        long long same = 0, different = k, total = k;
        int mod = 1e9 + 7; 
        for(int sections=2; sections<=n; sections++){
            same = different % mod;
            different = ((k-1)*(total)) % mod;
            total = (same + different) % mod;
        }
        
        return total;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends