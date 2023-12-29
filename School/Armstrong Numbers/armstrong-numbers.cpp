//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int power(int num, int pow){
	    int res = num;
	    for(int i=0; i<pow-1; i++){
		    res*=num;
	    }
	    return res;
    }
    
    
    string armstrongNumber(int n){
        // code here
        int sum = 0;
	    int digit;
	   // int count = 0;
	    int temp = n;

	   // while(temp!=0){
		  //  count++;
		  //  temp/=10;
	   // }

	   // temp=n;
	    while(temp!=0){
		    digit = temp%10;
		    sum+=power(digit,3);
		    temp/=10;
	    }
	    return n==sum? "Yes" : "No";
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends