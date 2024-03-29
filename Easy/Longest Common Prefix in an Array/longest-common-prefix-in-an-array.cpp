//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string res="";
        
        for(int i=0; i<arr[0].length(); i++){
            // for(auto &it: arr){
            //     if(i==it.size() || it[i]!=strs[0][i]){
            //         return res;
            //     }
            // }
            for(int j=0; j<N; j++){
                if(i==arr[j].length() || arr[j][i]!=arr[0][i]){
                    if(res.size()==0){
                        return "-1";
                    }
                    return res;
                }
            }
            res+=arr[0][i];
        }
        if(res.length()==0){
            return "-1";
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends