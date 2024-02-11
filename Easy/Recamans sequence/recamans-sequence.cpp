//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //Ist Method.
    //The below recursive method is giving TLE Error.
    // vector<int> helper(int i, int n, vector<int>& ans){
    //     if(i!=n){
           
        
    //         // else if(i==0)
    //         //     ans.push_back(0);
            
    //         // int val = ans[i-1]-i;
    //         if(ans[i-1]-i > 0 && find(ans.begin(), ans.end(), ans[i-1]-i) == ans.end()){
    //             ans.push_back(ans[i-1]-i);
    //         }
    //         else{
    //             ans.push_back(ans[i-1] + i);
    //         }
    //         helper(i+1, n, ans);
    //     }
    //     return ans;
    // }
    vector<int> recamanSequence(int n){
        // code here
        //Ist Method.
        // vector<int> ans;
        // ans.push_back(0);
        // ans =  helper(1, n, ans);
        // return ans;
        
        
        //IInd Method
        
        vector<int> ans = {0};
        unordered_set<int> included;
        
        for(int i=1; i<n; i++){
            int sub = ans.back() - i;
            int add = ans.back() + i;
            
            if(sub > 0 && included.find(sub) == included.end()){
                ans.push_back(sub);
                included.insert(sub);
            }
            else{
                ans.push_back(add);
                included.insert(add);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends