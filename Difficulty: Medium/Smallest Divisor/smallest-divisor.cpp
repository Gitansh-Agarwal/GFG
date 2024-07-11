//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int divResult(vector<int>&nums, int n, int divisor){
        int res=0;
        for(int i=0; i<n; i++){
            res+=ceil((double)nums[i]/(double)divisor);
        }
        return res;
    }
    
    void findMax(vector<int>&nums, int n, int& maxi){
        for(int i=0; i<n; i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }
    }
    
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int n=nums.size();
        int maxi;
        findMax(nums, n, maxi);
        
        
        if(n > K)//not necessray to write as it is not mentioned in the question
            return -1;//not possible to have the divisor.
        if(n==K){
            return maxi;//returning maxi
        }
        // int low=maxMin.first;
        int low=1;
        int high=maxi;
        int ans=-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(divResult(nums, n, mid) <= K){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;//or return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends