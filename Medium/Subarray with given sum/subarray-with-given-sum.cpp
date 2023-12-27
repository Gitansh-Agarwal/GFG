//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
      
        
        //Below solution is giving TLE Error, Time Complexity = O(N) and Space Complexity = O(N).
        // unordered_map<long long,int> ump;
        // vector<int> ans;
        
        // long long sum = 0;
        // int ansStart=-1;
        // int ansEnd=-1;
        
        
        // for(int i=0; i<n; i++){
            
        //     sum+=arr[i];
            
        //     if(sum == s){
                
        //         ansStart = 0;
        //         ansEnd = i;
        //         break;
                
                
        //     }
            
        //     else if(sum > s){
        //         if(ump.find(sum-s) != ump.end()){
        //             ansStart = ump[sum-s]+1;
        //             ansEnd = i;
        //             break;
                    
        //         }
                
                
                
        //     }
        //     ump[sum] = i;
            
        // }
        
        // if(ansStart==-1)
        //     ans.push_back(-1);
        // else{
        //     ans.push_back(ansStart+1);
        //     ans.push_back(ansEnd+1);
        // }
        // return ans;
        
        
        //Below method uses sliding window approach and
        // its Time Complexity = O(N), Space Complexity=O(1).
        
        int start=0;//left
        int end=0;//right
        long long currentSum=0;
        bool isFound = false;
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            currentSum+=arr[i];
            
            if(currentSum >= s){
                end=i;
                
                while(s<currentSum && start<end){
                    currentSum-=arr[start];
                    start++;
                }
            }
            if(currentSum==s){
                ans.push_back(start+1);
                ans.push_back(end+1);
                isFound = true;
                break;
            }
        }
        if(!isFound)
            ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends