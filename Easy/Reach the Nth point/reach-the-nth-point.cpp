//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		    
		    if(n == 1 || n==2)
		        return n;
		        
		    int first = 1;
		    int second = 2;
		    int temp;
		    int mod = 1e9 + 7;
		    
		    for(int i=3; i<=n; i++){
		        
		        temp = (first + second) % mod;
		        first = second;
		        second = temp;
		    }
		    
		    return second;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends