//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    //Using fibonacci Series or Approach
	    if(N == 1)
	        return 4;
	    if(N == 2)
	        return 9;
	        
	    long long int mod = 1e9 + 7;
	    int previous_two = 2, previous_one = 3, present = 0;
	    for(int i=3; i<=N; i++){
	        present = (previous_one + previous_two) % mod;
	        previous_two = previous_one;
	        previous_one = present;
	    }
	    return ((present%mod)*(present%mod)) % mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends