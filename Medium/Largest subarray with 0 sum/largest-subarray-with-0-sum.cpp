//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        //Brute Force Solution
    	//Below Solution is Partially Accepted.
    	//TC=O(N^2), extra SC=O(1).
    	
    // 	int maxLength=0;
    // 	for(int i=0; i<n; i++){
    // 		long long int sum=0;
    // 		for(int j=i; j<n; j++){
    // 			sum+=A[j];
    // 			if(sum==0){
    // 				int length=j-i+1;
    // 				maxLength=max(maxLength, length);
    // 			}
    // 		}
    // 	}
    // 	return maxLength;
    
    
    
    
    
    //Better Solution
	//TC=O(N), extra SC=O(N).
	unordered_map<int, int> mpp;
	int prefixSum=0;
	int length=0;
	int maxLength=0;
	for(int i=0; i<n; i++){
		prefixSum+=A[i];
		if(prefixSum == 0){
			maxLength=i+1;
		}
		else if(mpp.find(prefixSum) != mpp.end()){
			length = i - mpp[prefixSum];
			maxLength = max(maxLength, length);
		}
		else{
			mpp[prefixSum] = i;
		}
	}
	return maxLength;

    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> Aay1(m);
        for (int i = 0; i < m; ++i){
            cin>>Aay1[i];
        }
        Solution ob;
        cout<<ob.maxLen(Aay1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends