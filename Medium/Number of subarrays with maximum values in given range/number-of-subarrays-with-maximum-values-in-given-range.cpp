//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        
        //Time Limit Exceeded in below code, it is approximately O(N^3);
        
        // int max_int;
        // long count=0;
        
        // for(int sp=0; sp<n; sp++){
            
        //     for(int ep=sp; ep<n; ep++){
        //         max_int=INT32_MIN;
                
        //         for(int i=sp; i<=ep; i++){
        //             if(a[i]>max_int){
        //                 max_int=a[i];
        //             }
        //         }
        //         if(max_int>=L && max_int<=R){
        //             count++;
        //         }
                
        //     }
        // }
        // return count;
        
        
        
        
        // We can do it by using the concept of number line i.e. we can find the number of subarrays with 
        // value less than L(eqn (1)) and we can also find the number of subarrays with maximum value less than 
        // and equal to R(eqn (2)) and then finally we can subtract eqn(1) from eqn(2) to get the result.
        
        
        long lessThanLSubarrays=0;
        long lessThanEqualToRSubarrays=0;
        
        int j=0,k=0;
        for(int i=0;i<n;i++){
            
            if(a[i]<L){
                lessThanLSubarrays+=(i-j+1);
            }
            else{
                j=i+1;
            }
            
            
            if(a[i]<=R){
                lessThanEqualToRSubarrays+=(i-k+1);
            }
            else{
                k=i+1;
            }
        }
        
        return (lessThanEqualToRSubarrays - lessThanLSubarrays);
        
    }
    
    
    
    
    
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends