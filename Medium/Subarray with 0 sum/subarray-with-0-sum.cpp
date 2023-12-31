//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        
        //It takes around O(n^3) time so it given TLE error for below code.
        // int sum;
        // for(int sp=0; sp<n; sp++){
            
        //     for(int ep=sp; ep<n; ep++){
                
        //         sum=0;
        //         for(int i=sp; i<=ep; i++){
                    
        //             sum+=arr[i];
        //         }
        //         if(sum==0){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        
        
        //using prefix sum array and unordered_set
        int sum = 0;
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum == 0){
                return true;
            }
            if(st.find(sum)!=st.end()){
                return true;
            }
            st.insert(sum);
        }
        return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
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
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends