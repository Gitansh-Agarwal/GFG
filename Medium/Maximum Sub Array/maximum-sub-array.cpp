//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    //Brute Force Solution
	    //TC=O(N^2), SC=O(N), extra SC=O(1).
	   // long long sum=0, maxSum=0;
	   // vector<int> temp, ans;
	   // for(int i=0; i<n; i++){
	   //     if(a[i] < 0){
	   //         temp.clear();
	   //         sum=0;
	   //     }
	   //     else{
	   //         sum+=a[i];
	   //         temp.push_back(a[i]);
	   //         if(sum > maxSum){
	   //             maxSum=sum;
	   //             ans = temp; 
	   //         }
	   //         else if(sum == maxSum){
	   //             if(temp.size() > ans.size()){
	   //                 ans = temp;
	   //             }
	   //         }
	   //     }
	   // }
	   // if(ans.empty())
	   //     ans.push_back(-1);
	   // return ans;
	   
	    
	    
	    
	    //TC=O(N), SC=O(N), extra SC=O(1).
	    int sum = 0;
	    int max_sum = INT_MIN;
	    vector<int> result;
	    int start;
	    int ansStart = -1, ansEnd = -1;
	    int ansStartTemp, ansEndTemp;
	    int maxSubarrayLength;
	    int maxSubarrayLengthTemp;
	    for(int i=0; i<n; i++){
	        
	        if(a[i] < 0){
	            
	            sum = 0;
	            
	        }
	        else{
	            
	            if(sum == 0){
    	            start = i;
    	        }
    	        
    	        sum+=a[i];
    	        
    	        
    	        
    	        if(sum > max_sum){
    	            
    	            max_sum = sum;
    	            ansStart = start;
    	            ansEnd = i;
    	            maxSubarrayLength = ansEnd - ansStart;
    	        }
    	        else if(sum == max_sum){
    	            
    	            ansStartTemp = start;
    	            ansEndTemp = i;
    	            maxSubarrayLengthTemp = ansEndTemp - ansStartTemp;
    	            
    	            if(maxSubarrayLengthTemp > maxSubarrayLength){
    	                
    	                ansStart = ansStartTemp;
    	                ansEnd = ansEndTemp;
    	                
    	            }
    	            
    	        }
    	        
    	       // if(sum < 0){
    	            
    	       //     sum = 0;
    	       // }
	        }
	    }
	    
	    if(ansStart == -1){
	        
	        result.push_back(-1);
	        return result;
	        
	    }
	    else{
	        
	        for(int i=ansStart; i<=ansEnd; i++){
	            
	            result.push_back(a[i]);
	            
	        }
	        return result;
	        
	    }
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends